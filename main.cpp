#include "PolyCalc_first_try.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PolyCalc_first_try w;
    w.show(); 
    return a.exec();
}
