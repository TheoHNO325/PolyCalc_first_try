#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <cmath>
#include <QString>
#include <cstring>

using namespace std;

class Term
{
public:
    int data;
    int cof, zhi;
    Term* next;
    Term(int c = -1, int z = -1)
    {
        cof = c;
        zhi = z;
        next = NULL;
        data = 0;
    }
};

class PolyCalc
{
public:
    Term* a, * b, * c;
    int x1, x2;
    int init;

public:

    PolyCalc();
    ~PolyCalc();

    QString getPoly(QString a, int choose);

    void Insert(Term* head, int c, int z);

    QString Show(Term* head);

    int getValue(Term* head, int x);

    Term* derivative(Term* head);

    Term* add(Term* a, Term* b);

    Term* minus(Term*& a, Term*& b);

    Term* multiply(Term*& a, Term*& b);

    QString calmode(int mode, int choose = 0);

    QString getinput(QString sx,int choose);
    int getCof(char* a);

    void clear(Term* abc);
    void clear2();

    bool parsePolynomial(const QString& inputStr, Term* head);
    bool parseTerm(const QString& termStr, int& c, int& z);


};

#endif // POLY_H
