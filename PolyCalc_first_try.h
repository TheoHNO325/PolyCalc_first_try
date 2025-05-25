
#pragma once  
#ifndef POLYCALC_FIRST_TRY_H  
#define POLYCALC_FIRST_TRY_H  
#include <QtWidgets/QWidget>  
#include "ui_PolyCalc_first_try.h"  
#include "Poly.h"  
#include <QString>

QT_BEGIN_NAMESPACE  
namespace Ui { class PolyCalc_first_try; } // Fix: Update the class name to match the generated UI class  
QT_END_NAMESPACE  

class PolyCalc_first_try : public QWidget  
{  
    Q_OBJECT  

public:  
    PolyCalc_first_try(QWidget *parent = nullptr);
    ~PolyCalc_first_try();

private slots:  
    void on_add_clicked();  

    void on_minus_clicked();  

    void on_multiply_clicked();  

    void on_derivative_clicked();  

    void on_getvalue_clicked();  

    void on_clear2_clicked();


private:  
    Ui::PolyCalc_first_try* ui; // Fix: Update the pointer type to match the corrected class name  
    PolyCalc c;  
    QString strup;  
    QString strdown;  
};  

#endif