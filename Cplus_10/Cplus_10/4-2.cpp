#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(int r = 0, int i = 0) : real(r), imag(i)
	{
	}
	friend ostream& operator<< (ostream& os, Complex& operand);
	friend istream& operator >> (istream& is, Complex& operand);
	friend Complex operator+(Complex& op1, Complex& op2);
	friend Complex operator-(Complex& op1, Complex& op2);
	friend Complex operator*(Complex& op1, Complex& op2);
private:
	int real, imag;
};
ostream& operator<< (ostream& os, Complex& operand)
{
	os << operand.real << " + " << operand.imag << "i" << endl;
	return os;
}
istream& operator >> (istream& is, Complex& operand)
{
	is >> operand.real >> operand.imag;
	return is;
}
Complex operator+(Complex& op1, Complex& op2)
{
	return Complex(op1.real + op2.real, op1.imag + op2.imag);
}
Complex operator-(Complex& op1, Complex& op2)
{
	return Complex(op1.real - op2.real, op1.imag - op2.imag);
}
Complex operator*(Complex& op1, Complex& op2)
{
	return Complex((op1.real * op2.real) - (op1.imag * op2.imag)
		, (op1.real *op2.imag) + (op1.imag *op2.real));
}
int main()
{
	Complex x(2, 3);
	Complex y(4, 6);
	cout << "x + y = " << (x + y);
	cout << "x - y = " << (x - y);
	cout << "x * y = " << (x * y);
	Complex z = (x*y);
	cout << "z<<cout -> ";
	cout << z;
	cout << "z>>cin -> ";
	cin >> z;
	cout << z;

	return 0;
}