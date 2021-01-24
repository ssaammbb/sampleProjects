/********************************************************************************
** Form generated from reading UI file 'translate_search.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLATE_SEARCH_H
#define UI_TRANSLATE_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_translate_search
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textEdit;
    QTextEdit *textEdit_O;
    QPushButton *pushButton;
    QWidget *tab_2;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_O_2;
    QPushButton *pushButton_2;

    void setupUi(QWidget *translate_search)
    {
        if (translate_search->objectName().isEmpty())
            translate_search->setObjectName(QString::fromUtf8("translate_search"));
        translate_search->resize(400, 300);
        tabWidget = new QTabWidget(translate_search);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 311, 221));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 181, 41));
        textEdit_O = new QTextEdit(tab);
        textEdit_O->setObjectName(QString::fromUtf8("textEdit_O"));
        textEdit_O->setGeometry(QRect(10, 60, 181, 41));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 110, 93, 41));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 10, 181, 41));
        textEdit_O_2 = new QTextEdit(tab_2);
        textEdit_O_2->setObjectName(QString::fromUtf8("textEdit_O_2"));
        textEdit_O_2->setGeometry(QRect(10, 60, 181, 41));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 110, 93, 41));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(translate_search);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(translate_search);
    } // setupUi

    void retranslateUi(QWidget *translate_search)
    {
        translate_search->setWindowTitle(QApplication::translate("translate_search", "Form", nullptr));
        pushButton->setText(QApplication::translate("translate_search", "Translate", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("translate_search", "Spanish->English", nullptr));
        pushButton_2->setText(QApplication::translate("translate_search", "Translate", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("translate_search", "English->Spanish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class translate_search: public Ui_translate_search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATE_SEARCH_H
