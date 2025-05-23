/********************************************************************************
** Form generated from reading UI file 'PolyCalc_first_try.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLYCALC_FIRST_TRY_H
#define UI_POLYCALC_FIRST_TRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PolyCalc_first_try
{
public:
    QLineEdit *PolyA;
    QLineEdit *PolyB;
    QPushButton *add;
    QPushButton *minus;
    QPushButton *multiply;
    QPushButton *derivative;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *x1;
    QLineEdit *x2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *v1;
    QLineEdit *v2;
    QPushButton *getvalue;
    QPushButton *clear2;
    QLineEdit *PolyC;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QPlainTextEdit *plainTextEdit_2;

    void setupUi(QWidget *PolyCalc_first_try)
    {
        if (PolyCalc_first_try->objectName().isEmpty())
            PolyCalc_first_try->setObjectName("PolyCalc_first_try");
        PolyCalc_first_try->resize(600, 401);
        PolyA = new QLineEdit(PolyCalc_first_try);
        PolyA->setObjectName("PolyA");
        PolyA->setGeometry(QRect(150, 30, 381, 51));
        PolyA->setAutoFillBackground(false);
        PolyB = new QLineEdit(PolyCalc_first_try);
        PolyB->setObjectName("PolyB");
        PolyB->setGeometry(QRect(150, 100, 381, 51));
        add = new QPushButton(PolyCalc_first_try);
        add->setObjectName("add");
        add->setGeometry(QRect(150, 180, 81, 24));
        minus = new QPushButton(PolyCalc_first_try);
        minus->setObjectName("minus");
        minus->setGeometry(QRect(250, 180, 81, 24));
        multiply = new QPushButton(PolyCalc_first_try);
        multiply->setObjectName("multiply");
        multiply->setGeometry(QRect(350, 180, 81, 24));
        derivative = new QPushButton(PolyCalc_first_try);
        derivative->setObjectName("derivative");
        derivative->setGeometry(QRect(450, 180, 81, 24));
        verticalLayoutWidget = new QWidget(PolyCalc_first_try);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(150, 230, 131, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        x1 = new QLineEdit(verticalLayoutWidget);
        x1->setObjectName("x1");

        verticalLayout->addWidget(x1);

        x2 = new QLineEdit(verticalLayoutWidget);
        x2->setObjectName("x2");

        verticalLayout->addWidget(x2);

        verticalLayoutWidget_3 = new QWidget(PolyCalc_first_try);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(310, 230, 101, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        v1 = new QLineEdit(verticalLayoutWidget_3);
        v1->setObjectName("v1");

        verticalLayout_3->addWidget(v1);

        v2 = new QLineEdit(verticalLayoutWidget_3);
        v2->setObjectName("v2");

        verticalLayout_3->addWidget(v2);

        getvalue = new QPushButton(PolyCalc_first_try);
        getvalue->setObjectName("getvalue");
        getvalue->setGeometry(QRect(450, 230, 81, 24));
        clear2 = new QPushButton(PolyCalc_first_try);
        clear2->setObjectName("clear2");
        clear2->setGeometry(QRect(450, 280, 81, 24));
        PolyC = new QLineEdit(PolyCalc_first_try);
        PolyC->setObjectName("PolyC");
        PolyC->setGeometry(QRect(140, 330, 381, 51));
        plainTextEdit = new QPlainTextEdit(PolyCalc_first_try);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(30, 40, 91, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        plainTextEdit->setFont(font);
        plainTextEdit->setReadOnly(true);
        plainTextEdit_3 = new QPlainTextEdit(PolyCalc_first_try);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(30, 330, 91, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        plainTextEdit_3->setFont(font1);
        plainTextEdit_3->setReadOnly(true);
        plainTextEdit_4 = new QPlainTextEdit(PolyCalc_first_try);
        plainTextEdit_4->setObjectName("plainTextEdit_4");
        plainTextEdit_4->setGeometry(QRect(30, 210, 101, 31));
        QFont font2;
        font2.setItalic(true);
        plainTextEdit_4->setFont(font2);
        plainTextEdit_4->setReadOnly(true);
        plainTextEdit_2 = new QPlainTextEdit(PolyCalc_first_try);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(30, 110, 91, 41));
        plainTextEdit_2->setFont(font);
        plainTextEdit_2->setReadOnly(true);

        retranslateUi(PolyCalc_first_try);

        QMetaObject::connectSlotsByName(PolyCalc_first_try);
    } // setupUi

    void retranslateUi(QWidget *PolyCalc_first_try)
    {
        PolyCalc_first_try->setWindowTitle(QCoreApplication::translate("PolyCalc_first_try", "PolyCalc_first_try", nullptr));
        add->setText(QCoreApplication::translate("PolyCalc_first_try", "+", nullptr));
        minus->setText(QCoreApplication::translate("PolyCalc_first_try", "-", nullptr));
        multiply->setText(QCoreApplication::translate("PolyCalc_first_try", "\303\227", nullptr));
        derivative->setText(QCoreApplication::translate("PolyCalc_first_try", "d", nullptr));
        getvalue->setText(QCoreApplication::translate("PolyCalc_first_try", "getvalue", nullptr));
        clear2->setText(QCoreApplication::translate("PolyCalc_first_try", "clear", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("PolyCalc_first_try", "  PolyA", nullptr));
        plainTextEdit_3->setPlainText(QCoreApplication::translate("PolyCalc_first_try", "   Result", nullptr));
        plainTextEdit_4->setPlainText(QCoreApplication::translate("PolyCalc_first_try", "   Operation", nullptr));
        plainTextEdit_2->setPlainText(QCoreApplication::translate("PolyCalc_first_try", "  PolyB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PolyCalc_first_try: public Ui_PolyCalc_first_try {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLYCALC_FIRST_TRY_H
