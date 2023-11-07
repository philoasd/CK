#include "mainwindow.h"

#include <QApplication>
#include <QSharedMemory>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	// 防止程序启动两次
	static QSharedMemory* shareMem = new QSharedMemory("SingleApp"); //创建“SingleApp”的共享内存块
	if (!shareMem->create(1))//创建大小1b的内存
	{
		qApp->quit(); //创建失败，说明已经有一个程序运行，退出当前程序
		return -1;
	}

	MainWindow w;
	w.hide();
	return a.exec();
}
