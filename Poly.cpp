#include "Poly.h"
#include <QString>
#include <stack>
#include <cstring>

#include <QString>
#include <QRegularExpression>
#include <QDebug>
#define MAX 1000

PolyCalc::PolyCalc() {
	a = new Term();
	b = new Term();
	c = new Term();
	x1 = x2 = 0;
	init = 0;
}
PolyCalc::~PolyCalc() {
	delete a;
	delete b;
	delete c;

}

// deepseek写的
bool PolyCalc::parseTerm(const QString& termStr, int& c, int& z) {
	QString str = termStr.trimmed();
	if (str.isEmpty()) return false;
	
	// 检查是否为常数项（无x）
	if (!str.contains('x')) {
		bool ok;
		c = str.toInt(&ok);
		if (!ok) return false;
		z = 0;
		return true;
	}

	// 正则匹配带x的项
	QRegularExpression termReg(R"(^([+-]?)(\d*)(x)?(?:\^([+-]?\d+))?$)");
	QRegularExpressionMatch match = termReg.match(str);
	if (!match.hasMatch()) return false;

	QString signPart = match.captured(1);
	QString coeffPart = match.captured(2);
	QString xPart = match.captured(3);
	QString expPart = match.captured(4);

	// 解析系数
	int sign = 1;
	if (signPart == "-") sign = -1;
	else if (signPart == "+") sign = 1;

	if (coeffPart.isEmpty()) {
		c = (xPart.isEmpty()) ? 0 : sign * 1; // 处理纯数字情况
	}
	else {
		bool ok;
		c = coeffPart.toInt(&ok) * sign;
		if (!ok) return false;
	}

	// 解析指数
	if (xPart.isEmpty()) {
		z = 0;
	}
	else if (expPart.isEmpty()) {
		z = 1;
	}
	else {
		bool ok;
		z = expPart.toInt(&ok);
		if (!ok) return false;
	}

	return true;
}

// 解析整个多项式字符串
bool PolyCalc::parsePolynomial(const QString& inputStr, Term* head) {
	if (!head) return false;

	QString str = inputStr.trimmed().replace(" ", ""); // 去空格
	if (str.isEmpty()) return false;

	// 分割项（处理开头负号）
	QRegularExpression splitReg(R"((?=[+-]))");
	QStringList terms = str.split(splitReg);

	for (QString termStr : terms) {
		if (termStr.isEmpty()) continue;

		int c = 0, z = 0;
		if (!parseTerm(termStr, c, z)) {
			qWarning() << "Invalid term:" << termStr;
			return false;
		}

		if (c != 0) { // 忽略系数为0的项
			Insert(head, c, z);
		}
	}

	return true;
}
// 看起来deepseek写的很靠谱，尝试一下
QString PolyCalc::getPoly(QString s, int choose) {
	if (choose == 1) {
		parsePolynomial(s, a);
		return Show(a);
	}
	else {
		parsePolynomial(s, b);
		return Show(b);
	}
}


//QString PolyCalc::getPoly(QString s, int choose) {
//	if (choose == 1) {
//		a->next = NULL;
//
//		int i = 0;
//		int cof, index;
//		int l = 0;
//
//		char str[MAX];
//
//		string str1 = string(s.toLocal8Bit());
//		strcpy_s(str,MAX, str1.c_str());
//
//		while (*(str + i)) {
//			cof = getCof(str + i);
//			if (*(str + i) != 'x') i++;
//			while ((*(str + i) >= '0' && *(str + i) <= '9'))
//				i++;
//			if (*(str + i) == '+' || *(str + i) == '-' || *(str + i) == '\0')
//				index = 0;
//			else {
//				if (*(str + i) == 'x')
//				{
//					i++;
//					if (*(str + i) == '+' || *(str + i) == '-' || *(str + i) == '\0')
//						index = 1;
//					else
//						if (*(str + i) == '^')
//						{
//							i++;
//							index = getCof(str + i);
//							while ((*(str + i) >= '0' && *(str + i) <= '9') || (*(str + i) == '.'))
//								i++;
//						}
//				}
//			}
//			Insert(a, cof, index);
//		}
//		return Show(a);
//	}
//	else {
//		b->next = NULL;
//
//		int i = 0;
//		int cof;
//		int index;
//		int l = 0;
//
//		char str[MAX];
//
//		string str1 = string(s.toLocal8Bit());
//		strcpy_s(str,MAX, str1.c_str());
//
//		while (*(str + i)) {
//			cof = getCof(str + i); // 先得到x之前的系数
//			if (*(str + i) != 'x') i++;// 到达了了x的位置
//
//			while ((*(str + i) >= '0' && *(str + i) <= '9'))
//				i++;
//
//			if (*(str + i) == '+' || *(str + i) == '-' || *(str + i) == '\0')
//				index = 0;
//			else {
//				if (*(str + i) == 'x')
//				{
//					i++;
//					if (*(str + i) == '+' || *(str + i) == '-' || *(str + i) == '\0')
//						index = 1;
//					else
//						if (*(str + i) == '^')
//						{
//							i++;
//							index = getCof(str + i);
//							while ((*(str + i) >= '0' && *(str + i) <= '9') || (*(str + i) == '.'))
//								i++;
//						}
//				}
//			}
//			Insert(b, cof, index);
//		}
//		return Show(b);
//	}
//}

QString PolyCalc::getinput(QString sx,int choose) {
	char a[MAX];
	string str1 = string(sx.toLocal8Bit());
	strcpy_s(a,MAX, str1.c_str());
	stack<int> s;

	int i = 0;
	while ('0' <= *(a + i) && *(a + i) <= '9') {
		s.push(*(a + i) - '0'); i++;
	}
	int sum = 0;
	while (i--) {
		sum += s.top() * pow(10, i); s.pop();
	}
	if (choose == 1) x1 = sum;
	else if (choose == 2) x2 = sum;
	return QString::number(sum);
}

int PolyCalc::getCof(char* a) {
	stack<int> s;
	int i = 0;
	while ('0'<= * (a + i) && *(a+i) <='9') {
		s.push(*(a + i) - '0'); i++;
	}
	int sum = 0;
	while (i--) {
		sum += s.top() * pow(10, i); s.pop();
	}
	return sum;
}


QString PolyCalc::Show(Term* head) {
	Term* p = head->next;
	QString s = "";
	
	if (p == NULL) return s;
	if (p->zhi == 0)
			s += QString::number(p->cof);
	else if (p->zhi == 1)
	{
		if (p->cof == -1)
				s += " - ";
		else if (p->cof != 1)
			s += QString::number(p->cof);
		s += "x";
	}
	else
	{
		if (p->cof == -1)
				s += " - ";
		else if (p->cof != 1)
			s += QString::number(p->cof);
		s += "x ^ ";
		s += QString::number(p->zhi);
		s += " ";
	}
	p = p->next;

	// 之后的
	while (p != NULL)
	{
		if (p->cof > 0)
			s += " + ";
		if (p->zhi == 0)
			s += QString::number(p->cof);
		else if (p->zhi == 1)
		{
			if (p->cof != 1 && p->cof != -1)
			{
				s += QString::number(p->cof); s += " ";
			}
			else if (p->cof == -1)
				 s += " - ";
			s += "x";
		}
		else
		{
			if (p->cof == -1)
				s += " - ";
			else if (p->cof != 1)
			{
				s += QString::number(p->cof); s += " ";
			}
			s += "x ^ ";
			s += QString::number(p->zhi);
			s += " ";
		}
		p = p->next;
	}
	return s;
}

void PolyCalc::Insert(Term* head, int c, int z)
{
	Term* p = head;

	//第一个节点的情况
	if (p->next == NULL) {
		p->next = new Term(c, z);
		head->data++;
		return;
	}

	// 单独处理zhi=0的情况
	if (z == 0) {
		while (p->next != NULL) p = p->next;
		if (p->zhi == 0) {
			p->cof += c;
			if (p->cof == 0)
			{
				Term* q = head;
				while (q->next != p)
					q = q->next;
				q->next = p->next;
				delete p;
				head->data--;
			}
		}
		else {
			Term* q = new Term(c, z);
			q->next = p->next;
			p->next = q;
			head->data++;
		}
		return;
	}
	// 其他情况
	while (p->next != NULL)
	{
		if (p->zhi == z) {
			// cout << p->cof << " " << p->zhi << endl;
			p->cof += c;
			if (p->cof == 0)
			{
				Term* q = head;
				while (q->next != p)
					q = q->next;
				q->next = p->next;
				delete p;
				head->data--;
			}
			return;
		}
		if (p->next->zhi < z)
			break;
		p = p->next;

	}
	Term* q = new Term(c, z);
	q->next = p->next;
	p->next = q;
	head->data++;
	return;
}

void PolyCalc::clear(Term* abc) {
    Term* p, *q;
    p = abc;
    if (p->next != NULL) {
        q = p->next; // Initialize q before entering the loop
        while (q != NULL) {
            p->next = q->next; // Update the next pointer of p
            delete q;          // Delete the current node
            q = p->next;       // Move q to the next node
        }
    }
    return;
}

void PolyCalc::clear2() {
	clear(a); clear(b); clear(c);
}

Term* PolyCalc::derivative(Term* head)
{
	Term* c = new Term;
	Term* p = head->next;
	int l = 0;
	while (p != NULL && p->zhi > 0)
	{
		Insert(c, p->cof * p->zhi, p->zhi - 1);
		p = p->next;
	}
	return c;
}

Term* PolyCalc::add(Term* a, Term* b)
{
	Term* p = a->next;
	Term* q = b->next;
	
	if (p == NULL && q == NULL)
	{
		c->data = 0;
		return c;
	}
	if (p == NULL)
	{
		c->data = b->data;
		return b;
	}
	if (q == NULL)
	{
		c->data = a->data;
		return a;
	}
	while (p != NULL && q != NULL)
	{
		if (p->zhi == q->zhi)
		{
			if (p->cof + q->cof != 0)
			{
				Insert(c, p->cof + q->cof, p->zhi);
			}
			p = p->next;
			q = q->next;
		}
		else if (p->zhi > q->zhi)
		{
			Insert(c, p->cof, p->zhi);
			p = p->next;
		}
		else
		{
			Insert(c, q->cof, q->zhi);
			q = q->next;
		}
	}
	while (p != NULL)
	{
		Insert(c, p->cof, p->zhi);
		p = p->next;
	}
	while (q != NULL)
	{
		Insert(c, q->cof, q->zhi);
		q = q->next;
	}
	return c;
}

Term* PolyCalc::minus(Term*& a, Term*& b)
{
	Term* p = a->next;
	Term* q = b->next;
	while (p != NULL && q != NULL)
	{
		if (p->zhi == q->zhi)
		{
			if (p->cof - q->cof != 0)
			{
				Insert(c, p->cof - q->cof, p->zhi);
			}
			p = p->next;
			q = q->next;
		}
		else if (p->zhi > q->zhi)
		{
			Insert(c, p->cof, p->zhi);
			p = p->next;
		}
		else
		{
			Insert(c, -q->cof, q->zhi);
			q = q->next;
		}
	}
	while (p != NULL)
	{
		Insert(c, p->cof, p->zhi);
		p = p->next;
	}
	while (q != NULL)
	{
		Insert(c, -q->cof, q->zhi);
		q = q->next;
	}

	return c;
}

Term* PolyCalc::multiply(Term*& a, Term*& b)
{
	Term* p = a->next;

	while (p != NULL)
	{
		Term* d = new Term;
		Term* q = b->next;
		while (q != NULL)
		{
			Insert(d, p->cof * q->cof, p->zhi + q->zhi);
			q = q->next;
		}
		c = add(c, d);
		p = p->next;
	}
	return c;
}

int PolyCalc::getValue(Term* head, int x)
{
	Term* p = head->next;
	double sum = 0;
	while (p != NULL)
	{
		sum += p->cof * pow(x, p->zhi);
		p = p->next;
	}
	return sum;
}

QString PolyCalc::calmode(int mode, int choose) {
	QString str;
	if (mode == 1) {
		c = add(a, b);
		str = Show(c);
	}
	else if (mode == 2) {
		c = minus(a, b);
		str = Show(c);
	}
	else if (mode == 3) {
		c = multiply(a, b);
		str = Show(c);
	}
	else if (mode == 4) {
		c = derivative(a);
		str = Show(c);
	}
	else if (mode == 5) {
		int v = 0;
		if (choose == 1) v = getValue(a, x1);
		else if (choose == 2) v = getValue(b, x2);
		str = QString::number(v);
	}
	return str;
}