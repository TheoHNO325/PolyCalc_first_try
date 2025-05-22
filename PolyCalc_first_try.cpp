#include "PolyCalc_first_try.h"  
#include "ui_PolyCalc_first_try.h"  // 确保包含此头文件以定义 Ui::PolyCalc_first_try  
#include <QString>  
#include "Poly.h"  
#include <cstring>

PolyCalc_first_try::PolyCalc_first_try(QWidget *parent)
    : QWidget(parent), ui(new Ui::PolyCalc_first_try)  // 确保 Ui::PolyCalc_first_try 定义在头文件中
{  
    ui->setupUi(this);  
}  


PolyCalc_first_try::~PolyCalc_first_try()
{  
    delete ui;  
}


void PolyCalc_first_try::on_add_clicked()
{
    ui->PolyC->clear();
    c.clear(c.c);
    if (c.init == 0) {
        ui->PolyA->setText(c.getPoly(ui->PolyA->text(), 1));
        ui->PolyB->setText(c.getPoly(ui->PolyB->text(), 2));
        c.init = 2;
    }
    else if (c.init == 1) {
        ui->PolyB->setText(c.getPoly(ui->PolyB->text(), 2));
        c.init = 2;
    }

    // 获取算法结果并转换为QString
    QString result = c.calmode(1);
    // 设置结果文本到 Lineoutput
    ui->PolyC->setText(result);
}

void PolyCalc_first_try::on_minus_clicked()
{
    ui->PolyC->clear();
    c.clear(c.c);

    if (c.init == 0) {
        ui->PolyA->setText(c.getPoly(ui->PolyA->text(), 1));
        ui->PolyB->setText(c.getPoly(ui->PolyB->text(), 2));
        c.init = 2;
    }
    else if (c.init == 1) {
        ui->PolyB->setText(c.getPoly(ui->PolyB->text(), 2));
        c.init = 2;
    }
    // 获取算法结果并转换为QString
    QString result = c.calmode(2);
    // 设置结果文本到 Lineoutput
    ui->PolyC->setText(result);
}

void PolyCalc_first_try::on_multiply_clicked()
{
    ui->PolyC->clear();
    c.clear(c.c);
    if (c.init == 0) {
        ui->PolyA->setText(c.getPoly(ui->PolyA->text(), 1));
        ui->PolyB->setText(c.getPoly(ui->PolyB->text(), 2));
        c.init = 2;
    }
    else if (c.init == 1) {
        ui->PolyB->setText(c.getPoly(ui->PolyB->text(), 2));
        c.init = 2;
    }
    // 获取算法结果并转换为QString
    QString result = c.calmode(3);
    // 设置结果文本到 Lineoutput
    ui->PolyC->setText(result);
}

void PolyCalc_first_try::on_derivative_clicked()
{
    ui->PolyC->clear();
    c.clear(c.c);
    if (c.init == 0) {
        ui->PolyA->setText(c.getPoly(ui->PolyA->text(), 1));
        c.init = 1;
    }
    QString result = c.calmode(4);

    ui->PolyC->setText(result);
}

void PolyCalc_first_try::on_getvalue_clicked()
{
    ui->v1->clear();
    ui->v2->clear();

    if (c.init == 0) {
        ui->PolyA->setText(c.getPoly(ui->PolyA->text(), 1));
        ui->PolyB->setText(c.getPoly(ui->PolyB->text(), 2));
        c.init = 2;
    }
    else if (c.init == 1) {
        ui->PolyB->setText(c.getPoly(ui->PolyB->text(), 2));
        c.init = 2;
    }
    ui->x1->setText(c.getinput(ui->x1->text(), 1));

    ui->x2->setText(c.getinput(ui->x2->text(), 2));

    QString result1 = c.calmode(5,1);
    QString result2 = c.calmode(5,2);

    ui->v1->setText(result1);
    ui->v2->setText(result2);

}

void PolyCalc_first_try::on_clear2_clicked() 
{
	ui->PolyA->clear();
	ui->PolyB->clear();
	ui->PolyC->clear();
    c.clear2(); 
    c.init = 0;
}
