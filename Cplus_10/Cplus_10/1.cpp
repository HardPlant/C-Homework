#include <iostream>
#include <cstdlib>
using namespace std;
class String
{
public:
	String(char chr[])
	{
		int i = 0;
		for (char* current = chr; *current != '\0'; current++)
			i++;
		i++; // '\0' 포함
		str = new char[i];
		memcpy_s(str,i,chr,i);
		this->length = i;
	}
	char* display()
	{
		return str;
	}
	~String()
	{
		delete[] str;
	}
	String operator+(String& operand)
	{
		int newLength = this->length + operand.length - 2;
		char* newStr = new char[newLength];
		char* temp = newStr;
		memcpy_s(newStr,length-1, this->str, length-1); // '\0' 제외
		temp+= length - 1;
		memcpy_s(temp, operand.length-1, operand.str, operand.length-1);
		newStr[newLength] = '\0';
		return String(newStr);
	}
	bool operator!()
	{
		int i;
		char* current = this->str;
		for (i = 0; *current != '\0'; current++)
		{
			if (*current != ' ')
				i++;
		}
		if (i == 0) return true;
		else return false;
	}
	bool operator==(String& operand)
	{
		if (strcmp(this->str, operand.str) == 0) // -1, 1이면 다름
			return true;
		else return false;
	}
	bool operator!=(String& operand)
	{
		if (strcmp(this->str, operand.str) != 0) // -1, 1이면 다름
			return true;
		else return false;
	}
	bool operator<(String& operand)
	{
		if (strcmp(this->str, operand.str) == -1) // -1이면 this < operand
			return true;
		else return false;
	}
	bool operator>(String& operand)
	{
		if (strcmp(this->str, operand.str) == 1) // 1이면 this > operand
			return true;
		else return false;
	}
	bool operator>=(String& operand)
	{
		int result = strcmp(this->str, operand.str);
		if (result >= 0) // result = 0 or 1
			return true;
		else return false;
	}
	bool operator<=(String& operand)
	{
		int result = strcmp(this->str, operand.str);
		if (result <= 0)  // result = 0 or -1
			return true;
		else return false;
	}
private:
	char* str;
	int length;
};

int main()
{
	String s1("Hello ");
	String s2("World!");
	String s3 = s1 + s2;
	String s4(" ");
	String s5("Hello ");
	cout << s1.display() << endl;
	cout << s2.display() << endl;
	cout << s3.display() << endl;
	cout << "String s4 : " << !s4 << endl;
	cout << "s1(Hello) == s5(Hello) : " << (s1 == s5) << endl;
	cout << "s1(Hello) != s5(Hello) : " << (s1 != s5) << endl;
	cout << "s1(Hello) < s2(World!) : " << (s1 < s2) << endl;
	cout << "s1(Hello) > s2(World!) : " << (s1 > s2) << endl;
	cout << "s1(Hello) <= s2(World!) : " << (s1 <= s2) << endl;
	cout << "s1(Hello) >= s2(World!) : " << (s1 >= s2) << endl;

	return 0;
}