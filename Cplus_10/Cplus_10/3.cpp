#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Set
{
	const int max_size = 100;
public:
	Set()
	{
		length = 0;
		set = new int[max_size];
		for (int index = 0; index < max_size; index++)
			set[index] = 0;
	}

	void display()
	{
		cout << *this; // operator<<�� ���� ���� ����
	}
	Set operator+(int element)
	{
		for (int index = 0; index < length; index++)
		{
			if (set[index] == element)
			{
				cerr << "�ߺ��Դϴ�." << endl;
				return *this;
			}
		}
		if (length < max_size)
		{
			set[length] = element;
			length++;
			qsort(set, length, sizeof(int), compareInt); // ������� �����ϸ� �� ������ ���� �ӵ��� �� ����
			return *this;
		}
		else
		{
			cerr << "�迭�� ���� á���ϴ�." << endl;
		}
	}
	Set operator-(int element)
	{
		for (int index = 0; index < length; index++)
		{
			if (set[index] == element)
			{
				set[index] = set[length];
				length--;
				return *this;
			}
		}
	}
	Set operator|(Set& operand)
	{
		Set result;
		int* thisIterator = this->set;
		int* operIterator = operand.set;
		int thisCurrent = 0;
		int operCurrent = 0;
		while (thisCurrent < this->length && operCurrent < operand.length)
		{
			if (*thisIterator < *operIterator)
			{
				result + (*thisIterator);
				thisCurrent++;
				thisIterator++;
			}
			else if (*thisIterator > *operIterator)
			{
				result + (*operIterator);
				operCurrent++;
				operIterator++;
			}
			else
			{
				result + (*thisIterator); // �� ���Ҹ� �������μ� �ߺ� ����
				thisCurrent++;
				thisIterator++;
				operCurrent++;
				operIterator++;
			}
		}
		if (operCurrent == operand.length) // �� ������ ���� Ž������ ���
		{
			for (thisCurrent; thisCurrent <= this->length; thisCurrent++)
			{
				result + (*thisIterator);
				thisCurrent++;
				thisIterator++;
			}
		}
		else if (thisCurrent == this->length)
		{
			for (operCurrent; operCurrent <= operand.length; operCurrent++)
			{
				result + (*operIterator);
				operCurrent++;
				operIterator++;
			}
		}
		return result;
	}
	Set operator&(Set& operand)
	{
		Set result;
		int* thisIterator = this->set;
		int* operIterator = operand.set;
		int thisCurrent = 0;
		int operCurrent = 0;
		while (thisCurrent < this->length && operCurrent < operand.length)
		{
			if (*thisIterator < *operIterator)
			{
				thisCurrent++;
				thisIterator++;
			}
			else if (*thisIterator > *operIterator)
			{
				operCurrent++;
				operIterator++;
			}
			else
			{
				result + (*thisIterator); // ���� ��쿡�� ��� ���տ� ����
				thisCurrent++;
				thisIterator++;
				operCurrent++;
				operIterator++;
			}
			//�迭�� ���ĵ� �����̹Ƿ� �� ������ ���� �����ϸ� �ٸ� ���տ��� �������� ������ �ʿ� ����
		}
		return result;
	}
	bool operator==(Set& operand)
	{
		if (this->length != operand.length)
			return false;
		for (int index = 0; index <= this->length; index++)
		{
			if (this->set[index] != operand.set[index])
				return false;
		}
		return true;
	}
	friend ostream& operator<<(ostream &os, Set& operand)
	{
		os << "{";
		int index = 0;
		for (index; index < operand.length; index++)
		{
			cout << operand.set[index];
			if (index != operand.length - 1)
				cout << ", ";
		}

		os << "}" << endl;

		return os;
	}	
	friend istream& operator>>(istream &is, Set& operand)
	{
		int element;
		while (!(is.peek() == '\n')) // ��Ʈ���� ���� ���ڰ� \n�� �ƴϸ� �б�
		{
			is >> element;
			operand + element;
		}
		return is;
	}
private:
	int* set;
	int length;
	static int compareInt(const void *a, const void *b) // qsort�� ����ϱ� ���� static ����
	{
		int arg1 = *(const int*)a;
		int arg2 = *(const int*)b;
		if (arg1 < arg2) return -1;
		if (arg1 > arg2) return 1;
		return 0;
	}
};

int main()
{
	Set A;
	cout << "���� A�� ���Ҵ� : " << endl;
	A + 3;
	A.display();
	A + 4;
	A.display();
	A + 3;
	A.display();
	A - 4;
	A.display();
	A + 4;
	A.display();
	cout << "���� B�� ���Ҵ� : " << endl;
	Set B;
	B + 3;
	B.display();
	B + 4;
	B.display();
	B + 5;
	B.display();
	cout << "���� A�� B�� ������ : " << endl;
	(A | B).display();
	cout << "���� A�� B�� ������ : " << endl;
	(A & B).display();
	cout << "���� A�� B�� ==������ : " << endl;
	if (A == B)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "���� A�� <<������ : " << endl;
	cout << A;
	cout << "���� A�� >>������ : " << endl;
	cin >> A;
	A.display();

	return 0;
}