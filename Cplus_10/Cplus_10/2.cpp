#include <iostream>
using namespace std;

class Time {
public:
	Time() : hour(1), minute(0), second(0)
	{
	}
	Time(int s)
	{
		hour = s / (60 * 60);
		s = s % (60 * 60);
		minute = s / 60;
		s = s % 60;
		second = s;
	}
	void display()
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}
	Time operator+(int operand)
	{
		int total_second = this->hour * (60 * 60)
							+ this->minute * 60 
							+ this->second + operand;
		return Time(total_second);
	}
	Time operator-(int operand)
	{
		int total_second = this->hour * (60 * 60)
							+ this->minute * 60
							+ this->second - operand;
		return Time(total_second);
	}
	bool operator< (Time& operand)
	{
		if (this->hour > operand.hour) return true;
		if (this->minute > operand.minute) return true;
		if (this->second > operand.second) return true;
		return false;
	}
	bool operator> (Time& operand) // 일어난 순서로 start가 end보다 먼저
	{
		if (this->hour < operand.hour) return true;
		if (this->minute < operand.minute) return true;
		if (this->second < operand.second) return true;
		return false;
	}
	friend istream& operator>>(istream& is, Time& operand)
	{
		is >> operand.hour >> operand.minute >> operand.second;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Time& operand)
	{
		os << operand.hour << ":" << operand.minute << ":"
			<< operand.second;
		return os;
	}
private:
	int hour, minute, second;
};

int main()
{
	Time start;
	Time end = start + 1000;
	cout << "end = start + 1000" << endl;
	end.display();
	end = end - 500;
	cout << "end = end - 500" << endl;
	end.display();
	cout << "start < end : " << (start<end) << endl;
	cout << "start > end : " << (start>end) << endl;
	cout << "cin>> ";
	cin >> end;
	cout << "cout<< ";
	cout << end << endl;
	return 0;
}