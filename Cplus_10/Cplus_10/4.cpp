#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(int r= 0, int i=0) : real(r), imag(i)
	{
	}
	friend ostream& operator<< (ostream& os, Complex& operand)
	{
		os << operand.real << " + " << operand.imag << "i" << endl;
		return os;
	}
	friend istream& operator>>(istream& is, Complex& operand)
	{
		is >> operand.real >> operand.imag;
		return is;
	}
	Complex operator+(Complex& operand)
	{
		return Complex(this->real + operand.real, this->imag + operand.imag);
	}
	Complex operator-(Complex& operand)
	{
		return Complex(this->real - operand.real, this->imag - operand.imag);
	}
	Complex operator*(Complex& operand)
	{
		return Complex((this->real * operand.real) - (this->imag * operand.imag)
						, (this->real *operand.imag) + (this->imag *operand.real));
	}
private:
	int real, imag;
};
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