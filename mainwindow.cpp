#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	dirPath = QApplication::applicationDirPath();
	m_Settings = new QSettings(dirPath + "/Config.ini", QSettings::IniFormat);

	InitPort();

	// 打开界面时的一些操作
	connect(this, &MainWindow::OpenWindowOperation, this, [&]() {
		ui->pushButton_ConnectedPort->click();
		}, Qt::QueuedConnection);
	emit OpenWindowOperation();
}

MainWindow::~MainWindow()
{
	delete m_Settings;
	delete ui;
}

void MainWindow::InitPort()
{
	// 获取可用的串口列表
	QList<QSerialPortInfo> list_Serial = QSerialPortInfo::availablePorts();
	// 对串口名进行升序排序
	std::sort(list_Serial.begin(), list_Serial.end(), [](const QSerialPortInfo& s1, const QSerialPortInfo& s2) {
		return s1.portName().toInt() < s2.portName().toInt();
		});
	// 将串口名添加到comboBox中
	foreach(const QSerialPortInfo & portInfo, list_Serial)
	{
		ui->comboBox_SerialNumber->addItem(portInfo.portName());
	}

	m_Settings->beginGroup("ComPort");
	ui->comboBox_SerialNumber->setCurrentIndex(m_Settings->value("SerialPort", 0).toInt());

	// 波特率
	ui->lineEdit_Bits->setText(m_Settings->value("BoundRate", "9600").toString());

	// 数据位
	ui->lineEdit_DataBits->setText(m_Settings->value("DataBits", "8").toString());

	// 校验位
	QList<QString> list_Parity = { "None", "Odd", "Even", "Mark", "Space" };
	foreach(const QString & parity, list_Parity)
	{
		ui->comboBox_Parity->addItem(parity);
	}
	ui->comboBox_Parity->setCurrentIndex(m_Settings->value("Parity", 0).toInt());

	// 停止位
	ui->lineEdit_StopBits->setText(m_Settings->value("StopBits", "1").toString());

	// 数据流控制
	QList<QString> list_FlowControl = { "None", "Hardware", "Software", "Unknown" };
	foreach(const QString & flowControl, list_FlowControl)
	{
		ui->comboBox_FlowControl->addItem(flowControl);
	}
	ui->comboBox_FlowControl->setCurrentIndex(m_Settings->value("FlowControl", 0).toInt());
	m_Settings->endGroup();

	ui->pushButton_DisConnectedPort->setEnabled(false);
}

bool MainWindow::ConnectPort()
{
	m_SerialPort = new QSerialPort(this);

	// 设置串口名
	m_SerialPort->setPortName(ui->comboBox_SerialNumber->currentText());
	if (!m_SerialPort->open(QIODevice::ReadWrite))// 打开串口
	{
		QMessageBox::warning(this, "Warning", "Open Serial Port Failed!!!");
		delete m_SerialPort;
		return false;
	}

	m_SerialPort->setBaudRate(ui->lineEdit_Bits->text().toInt()); // 设置波特率

	// 设置数据位
	switch (ui->lineEdit_DataBits->text().toInt())
	{
	case 5: {
		m_SerialPort->setDataBits(QSerialPort::Data5);
		break;
	}
	case 6: {
		m_SerialPort->setDataBits(QSerialPort::Data6);
		break;
	}
	case 7: {
		m_SerialPort->setDataBits(QSerialPort::Data7);
		break;
	}
	case 8: {
		m_SerialPort->setDataBits(QSerialPort::Data8);
		break;
	}
	default: {
		QMessageBox::critical(nullptr, "Error", "Data bits Error");
		break;
	}
	}

	// 设置校验位
	switch (ui->comboBox_Parity->currentIndex())
	{
	case 0: {
		m_SerialPort->setParity(QSerialPort::NoParity);
		break;
	}
	case 1: {
		m_SerialPort->setParity(QSerialPort::OddParity);
		break;
	}
	case 2: {
		m_SerialPort->setParity(QSerialPort::EvenParity);
		break;
	}
	case 3: {
		m_SerialPort->setParity(QSerialPort::MarkParity);
		break;
	}
	case 4: {
		m_SerialPort->setParity(QSerialPort::SpaceParity);
		break;
	}
	}

	// 设置停止位
	switch (ui->lineEdit_StopBits->text().toInt())
	{
	case 1: {
		m_SerialPort->setStopBits(QSerialPort::OneStop);
		break;
	}
	case 2: {
		m_SerialPort->setStopBits(QSerialPort::TwoStop);
		break;
	}
	case 3: {
		m_SerialPort->setStopBits(QSerialPort::OneAndHalfStop);
		break;
	}
	case -1: {
		m_SerialPort->setStopBits(QSerialPort::UnknownStopBits);
		break;
	}
	default: {
		QMessageBox::critical(nullptr, "Error", "Stop bits Error");
		break;
	}
	}

	// 设置流控制
	switch (ui->comboBox_FlowControl->currentIndex())
	{
	case 0: {
		m_SerialPort->setFlowControl(QSerialPort::NoFlowControl);
		break;
	}
	case 1: {
		m_SerialPort->setFlowControl(QSerialPort::HardwareControl);
		break;
	}
	case 2: {
		m_SerialPort->setFlowControl(QSerialPort::SoftwareControl);
		break;
	}
	case 3: {
		m_SerialPort->setFlowControl(QSerialPort::UnknownFlowControl);
		break;
	}
	}

	return true;
}

void MainWindow::DisConnectPort()
{
	m_SerialPort->close();
	delete m_SerialPort;
}

bool MainWindow::SendAndReceiveSerialData(std::string sendData, int flag)
{
	QString Data = QString::fromStdString(sendData) + "=" + QString::number(flag) + "\r\n";
	if (m_SerialPort->write(Data.toLatin1()) != -1) {
		ui->textEdit->append("send serial data: " + Data);
		m_SerialPort->waitForReadyRead(200); // 等待接收数据

		QByteArray data = m_SerialPort->readAll();
		if (data == "ERROR\r\n" || data.length() == 0) {
			ui->textEdit->append("receive error serial data!!!\n");
			return false;
		}

		ui->textEdit->append("receive serial data: " + data);
		return true;
	}
	return false;
}

bool MainWindow::InitFotia()
{
	// Mode
	if (!SendAndReceiveSerialData("Mode", 13)) {
		ui->textEdit->append("Set mode failed!!!\n");
		//return false;
	}

	// SHT
	if (!SendAndReceiveSerialData("SHT", 1)) {
		QMessageBox::warning(this, "warning", "SHT On Error!!!");
		ui->textEdit->append("SHT On Error\n");
		return false;
	}

	// QSW
	if (!SendAndReceiveSerialData("QSW", 1)) {
		QMessageBox::warning(this, "warning", "QSW On Error!!!");
		ui->textEdit->append("QSW On Error\n");
		return false;
	}

	// DI1
	if (!SendAndReceiveSerialData("DI1", 1)) {
		QMessageBox::warning(this, "warning", "DI1 On Error!!!");
		ui->textEdit->append("DI1 On Error\n");
		return false;
	}

	return true;
}

bool MainWindow::CloseFotia()
{
	ui->textEdit->append("start close fotia:\n");
	// DIO
	if (!SendAndReceiveSerialData("DI1", 0)) {
		QMessageBox::warning(this, "warning", "DI1 Off Error!!!");
		ui->textEdit->append("DI1 Off Error\n");
		return false;
	}
	// QSW
	if (!SendAndReceiveSerialData("QSW", 0)) {
		QMessageBox::warning(this, "warning", "QSW Off Error!!!");
		ui->textEdit->append("QSW Off Error\n");
		return false;
	}
	// SHT
	if (!SendAndReceiveSerialData("SHT", 0)) {
		QMessageBox::warning(this, "warning", "SHT Off Error!!!");
		ui->textEdit->append("SHT Off Error\n");
		return false;
	}

	return true;
}

void MainWindow::on_pushButton_ConnectedPort_clicked()
{
	// 打开串口
	if (!ConnectPort()) {
		this->show();
		return;
	}

	// 初始化激光器
	if (!InitFotia()) {
		QMessageBox::critical(this, "Critical", "Init Laser failed!!!");
		DisConnectPort();
		this->show();
		return;
	}

#pragma region 写串口配置信息
	m_Settings->beginGroup("ComPort");
	m_Settings->setValue("SerialPort", ui->comboBox_SerialNumber->currentIndex());
	m_Settings->setValue("BoundRate", ui->lineEdit_Bits->text().toInt());
	m_Settings->setValue("DataBits", ui->lineEdit_DataBits->text().toInt());
	m_Settings->setValue("Parity", ui->comboBox_Parity->currentIndex());
	m_Settings->setValue("StopBits", ui->lineEdit_StopBits->text().toInt());
	m_Settings->setValue("FlowControl", ui->comboBox_FlowControl->currentIndex());
	m_Settings->endGroup();
#pragma endregion

	// 启动软件
	QString str = dirPath + "/UV10-22I0128/3DLaser_S6.exe";
	//QString str = "C:\\Users\\Admin\\Desktop\\DEMO\\Demo_CK.exe";

	connect(&m_Process, static_cast<void (QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, [&]() {
		//m_Process.waitForFinished(-1);
		ui->textEdit->append("software quit!!!\n");
		ui->pushButton_DisConnectedPort->click();
		});
	connect(&m_Process, &QProcess::started, this, [&]() {
		ui->textEdit->append("software start!!!\n");
		ui->pushButton_ConnectedPort->setEnabled(false);
		ui->pushButton_DisConnectedPort->setEnabled(true);
		this->hide();
		});
	connect(&m_Process, &QProcess::errorOccurred, this, [&]() {
		QMessageBox::critical(this, "Critical", "Cann't Find The Software!!!");
		ui->textEdit->append("software start failed!!!\n");
		CloseFotia();
		this->show();
		return;
		});
	m_Process.start(str);
}

void MainWindow::on_pushButton_DisConnectedPort_clicked()
{
	if (!CloseFotia()) {
		QMessageBox::critical(this, "Critical", "Close Laser failed!!!");
		return;
	}

	DisConnectPort();

	ui->pushButton_ConnectedPort->setEnabled(true);
	ui->pushButton_DisConnectedPort->setEnabled(false);

	ui->textEdit->append("app quit!!!\n");
	qApp->quit();
}

