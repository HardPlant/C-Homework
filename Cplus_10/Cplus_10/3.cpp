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
		cout << *this; // operator<<에 기존 정의 이전
	}
	Set operator+(int element)
	{
		for (int index = 0; index < length; index++)
		{
			if (set[index] == element)
			{
				cerr << "중복입니다." << endl;
				return *this;
			}
		}
		if (length < max_size)
		{
			set[length] = element;
			length++;
			qsort(set, length, sizeof(int), compareInt); // 결과값을 정렬하면 두 집합을 빠른 속도로 비교 가능
			return *this;
		}
		else
		{
			cerr << "배열이 가득 찼습니다." << endl;
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
				result + (*thisIterator); // 한 원소만 넣음으로서 중복 방지
				thisCurrent++;
				thisIterator++;
				operCurrent++;
				operIterator++;
			}
		}
		if (operCurrent == operand.length) // 한 집합을 전부 탐색했을 경우
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
				result + (*thisIterator); // 같은 경우에만 결과 집합에 삽입
				thisCurrent++;
				thisIterator++;
				operCurrent++;
				operIterator++;
			}
			//배열이 정렬된 상태이므로 한 집합의 끝에 도달하면 다른 집합에서 교집합을 점검할 필요 없음
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
		while (!(is.peek() == '\n')) // 스트림의 다음 글자가 \n이 아니면 읽기
		{
			is >> element;
			operand + element;
		}
		return is;
	}
private:
	int* set;
	int length;
	static int compareInt(const void *a, const void *b) // qsort를 사용하기 위해 static 선언
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
	cout << "집합 A의 원소는 : " << endl;
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
	cout << "집합 B의 원소는 : " << endl;
	Set B;
	B + 3;
	B.display();
	B + 4;
	B.display();
	B + 5;
	B.display();
	cout << "집합 A와 B의 합집합 : " << endl;
	(A | B).display();
	cout << "집합 A와 B의 교집합 : " << endl;
	(A & B).display();
	cout << "집합 A와 B의 ==연산자 : " << endl;
	if (A == B)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "집합 A의 <<연산자 : " << endl;
	cout << A;
	cout << "집합 A의 >>연산자 : " << endl;
	cin >> A;
	A.display();

	return 0;
}