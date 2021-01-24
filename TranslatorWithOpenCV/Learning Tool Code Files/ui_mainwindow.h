/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *imgC;
    QPushButton *pushButton;
    QPushButton *searchB;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QMenu *menuThe_Language_tool;
    QMenu *menuInfo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        MainWindow->setStyleSheet(QString::fromUtf8("border-image: url(:/new/IMG/havana.jpg);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 0, 311, 171));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        imgC = new QPushButton(tab);
        imgC->setObjectName(QString::fromUtf8("imgC"));
        imgC->setGeometry(QRect(10, 10, 101, 28));
        imgC->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 50, 101, 28));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        searchB = new QPushButton(tab);
        searchB->setObjectName(QString::fromUtf8("searchB"));
        searchB->setGeometry(QRect(10, 90, 101, 28));
        searchB->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(130, 10, 171, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        plainTextEdit = new QPlainTextEdit(tab_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 0, 301, 141));
        plainTextEdit->setReadOnly(true);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        menuThe_Language_tool = new QMenu(menuBar);
        menuThe_Language_tool->setObjectName(QString::fromUtf8("menuThe_Language_tool"));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QString::fromUtf8("menuInfo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuThe_Language_tool->menuAction());
        menuBar->addAction(menuInfo->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        imgC->setText(QApplication::translate("MainWindow", "Choose IMG", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Matching Game", nullptr));
        searchB->setText(QApplication::translate("MainWindow", "Search a Word", nullptr));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Image Name</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Learn", nullptr));
        plainTextEdit->setPlainText(QApplication::translate("MainWindow", "The Language Tool                                            \n"
"\n"
"Created by Justin Deng and Sam Britten with Windows Visual Studio and Qt                        \n"
"\n"
"Uses OpenCV and Qt libraries", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Info", nullptr));
        menuThe_Language_tool->setTitle(QApplication::translate("MainWindow", "The Language tool", nullptr));
        menuInfo->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
