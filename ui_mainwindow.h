/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox_SerialNumber;
    QLineEdit *lineEdit_Bits;
    QLineEdit *lineEdit_DataBits;
    QComboBox *comboBox_Parity;
    QLineEdit *lineEdit_StopBits;
    QComboBox *comboBox_FlowControl;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_ConnectedPort;
    QPushButton *pushButton_DisConnectedPort;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(385, 434);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout_3->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setPointSize(12);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        comboBox_SerialNumber = new QComboBox(centralwidget);
        comboBox_SerialNumber->setObjectName(QString::fromUtf8("comboBox_SerialNumber"));
        comboBox_SerialNumber->setFont(font);

        verticalLayout_2->addWidget(comboBox_SerialNumber);

        lineEdit_Bits = new QLineEdit(centralwidget);
        lineEdit_Bits->setObjectName(QString::fromUtf8("lineEdit_Bits"));
        lineEdit_Bits->setFont(font);

        verticalLayout_2->addWidget(lineEdit_Bits);

        lineEdit_DataBits = new QLineEdit(centralwidget);
        lineEdit_DataBits->setObjectName(QString::fromUtf8("lineEdit_DataBits"));
        lineEdit_DataBits->setFont(font);

        verticalLayout_2->addWidget(lineEdit_DataBits);

        comboBox_Parity = new QComboBox(centralwidget);
        comboBox_Parity->setObjectName(QString::fromUtf8("comboBox_Parity"));
        comboBox_Parity->setFont(font);

        verticalLayout_2->addWidget(comboBox_Parity);

        lineEdit_StopBits = new QLineEdit(centralwidget);
        lineEdit_StopBits->setObjectName(QString::fromUtf8("lineEdit_StopBits"));
        lineEdit_StopBits->setFont(font);

        verticalLayout_2->addWidget(lineEdit_StopBits);

        comboBox_FlowControl = new QComboBox(centralwidget);
        comboBox_FlowControl->setObjectName(QString::fromUtf8("comboBox_FlowControl"));
        comboBox_FlowControl->setFont(font);

        verticalLayout_2->addWidget(comboBox_FlowControl);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 5);

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_ConnectedPort = new QPushButton(centralwidget);
        pushButton_ConnectedPort->setObjectName(QString::fromUtf8("pushButton_ConnectedPort"));
        pushButton_ConnectedPort->setFont(font);

        horizontalLayout_2->addWidget(pushButton_ConnectedPort);

        pushButton_DisConnectedPort = new QPushButton(centralwidget);
        pushButton_DisConnectedPort->setObjectName(QString::fromUtf8("pushButton_DisConnectedPort"));
        pushButton_DisConnectedPort->setFont(font);

        horizontalLayout_2->addWidget(pushButton_DisConnectedPort);


        verticalLayout_3->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 385, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Com Port Config", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Serial Number:", nullptr));
        label->setText(QApplication::translate("MainWindow", "Bits per second:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Data bits:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Parity:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Stop bits:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Flow control:", nullptr));
        pushButton_ConnectedPort->setText(QApplication::translate("MainWindow", "Connected", nullptr));
        pushButton_DisConnectedPort->setText(QApplication::translate("MainWindow", "DisConnected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
