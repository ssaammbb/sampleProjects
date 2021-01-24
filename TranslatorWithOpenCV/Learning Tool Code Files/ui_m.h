/********************************************************************************
** Form generated from reading UI file 'm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_M_H
#define UI_M_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_M
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QPushButton *End;

    void setupUi(QWidget *M)
    {
        if (M->objectName().isEmpty())
            M->setObjectName(QString::fromUtf8("M"));
        M->resize(425, 380);
        pushButton = new QPushButton(M);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 30, 93, 28));
        pushButton_2 = new QPushButton(M);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 80, 93, 28));
        pushButton_3 = new QPushButton(M);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 130, 93, 28));
        pushButton_4 = new QPushButton(M);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(250, 180, 93, 28));
        pushButton_5 = new QPushButton(M);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(250, 230, 93, 28));
        checkBox = new QCheckBox(M);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(60, 30, 101, 20));
        checkBox_2 = new QCheckBox(M);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(60, 80, 101, 20));
        checkBox_3 = new QCheckBox(M);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(60, 130, 101, 20));
        checkBox_4 = new QCheckBox(M);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(60, 180, 101, 20));
        checkBox_5 = new QCheckBox(M);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(60, 230, 101, 20));
        End = new QPushButton(M);
        End->setObjectName(QString::fromUtf8("End"));
        End->setGeometry(QRect(120, 290, 131, 41));

        retranslateUi(M);
        QObject::connect(End, SIGNAL(clicked()), M, SLOT(close()));

        QMetaObject::connectSlotsByName(M);
    } // setupUi

    void retranslateUi(QWidget *M)
    {
        M->setWindowTitle(QApplication::translate("M", "Form", nullptr));
        pushButton->setText(QApplication::translate("M", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("M", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("M", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("M", "PushButton", nullptr));
        pushButton_5->setText(QApplication::translate("M", "PushButton", nullptr));
        checkBox->setText(QApplication::translate("M", "CheckBox", nullptr));
        checkBox_2->setText(QApplication::translate("M", "CheckBox", nullptr));
        checkBox_3->setText(QApplication::translate("M", "CheckBox", nullptr));
        checkBox_4->setText(QApplication::translate("M", "CheckBox", nullptr));
        checkBox_5->setText(QApplication::translate("M", "CheckBox", nullptr));
        End->setText(QApplication::translate("M", "End Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class M: public Ui_M {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_M_H
