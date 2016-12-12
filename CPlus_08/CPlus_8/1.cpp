#include <iostream>
#include <string>
#include "selector.h"
using namespace std;

class Coffee
{
public:
	Coffee()
	{
		cout << "<커피>" << endl;
	}
};

class Latte : public Coffee
{
public:
	Latte()
	{
		printName("라떼");
	}
	void printName(string name)
	{
		cout << name << " 입니다." <<endl;
	}
};
class Mocha : public Coffee
{
public:
	Mocha()
	{
		printName("모카");
	}
	void printName(string name)
	{
		cout << name << " 입니다." << endl;
	}
};
class Americano : public Coffee
{
public:
	Americano()
	{
		printName("아메리카노");
	}
	void printName(string name)
	{
		cout << name << " 입니다." << endl;
	}
};

int One()
{
	Americano A;
	Latte L;
	Mocha M;
	return 0;
}