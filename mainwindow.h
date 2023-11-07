#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMessageBox>
#include <qprocess.h>
#include <qsettings.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

signals:
	void OpenWindowOperation();

private:
	/// <summary>
	/// 初始化串口
	/// </summary>
	void InitPort();

	/// <summary>
	/// 连接串口
	/// </summary>
	/// <returns></returns>
	bool ConnectPort();

	/// <summary>
	/// 断开串口连接
	/// </summary>
	void DisConnectPort();

	/// <summary>
	/// 发送并且接受串口数据
	/// </summary>
	/// <param name="sendData">发送的信息</param>
	/// <param name="flag">开关变量</param>
	/// <returns></returns>
	bool SendAndReceiveSerialData(std::string sendData, int flag);

	/// <summary>
	/// 初始化激光器
	/// </summary>
	/// <returns></returns>
	bool InitFotia();

	/// <summary>
	/// 关闭激光器
	/// </summary>
	/// <returns></returns>
	bool CloseFotia();

private slots:
	void on_pushButton_ConnectedPort_clicked();

	void on_pushButton_DisConnectedPort_clicked();

private:
	Ui::MainWindow* ui;
	QSerialPort* m_SerialPort;//串口
	QProcess m_Process;//进程
	QString dirPath;//当前程序所在目录
	QSettings* m_Settings;//配置文件
};
#endif // MAINWINDOW_H
