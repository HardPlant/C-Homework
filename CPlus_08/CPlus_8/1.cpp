#include <iostream>
#include <string>
#include "selector.h"
using namespace std;

class Coffee
{
public:
	Coffee()
	{
		cout << "<Ŀ��>" << endl;
	}
};

class Latte : public Coffee
{
public:
	Latte()
	{
		printName("��");
	}
	void printName(string name)
	{
		cout << name << " �Դϴ�." <<endl;
	}
};
class Mocha : public Coffee
{
public:
	Mocha()
	{
		printName("��ī");
	}
	void printName(string name)
	{
		cout << name << " �Դϴ�." << endl;
	}
};
class Americano : public Coffee
{
public:
	Americano()
	{
		printName("�Ƹ޸�ī��");
	}
	void printName(string name)
	{
		cout << name << " �Դϴ�." << endl;
	}
};

int One()
{
	Americano A;
	Latte L;
	Mocha M;
	return 0;
}