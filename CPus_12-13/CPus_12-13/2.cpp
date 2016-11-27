#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class CaesarPassword
{
public:
	string encrypt(string plain)
	{
		string result;
		char* current = &plain[0];
		while (*current != '\0')
		{
			if (isAlphabet(*current))
			{
				int index = plainText.find(*current);
				if (index != string::npos)
					result += (protectedText[index]);
			}
			else
			{
				result += *current;
			}
			current++;
		}
		return result;
	}
private:
	string plainText	 = "abcdefghijklmnopqrstuvwxyz";
	string protectedText = "DEFGHIJKLMNOPQRSTUVWXYZABC";
	bool isAlphabet(char ch)
	{
		if ('a' <= ch && ch <= 'z') return true;
		else return false;
	}
};

int main()
{
	string toRead, toSave;
	cout << "�о�� ������?";
	cin >> toRead;
	cout << "������ ������?";
	cin >> toSave;

	ifstream read;
	ofstream save;
	
	read.open(toRead);
	save.open(toSave);
	if (read.fail() || save.fail())
	{
		cout << "���� �б⿡ �����߽��ϴ�." << endl;
		return -1;
	}
	CaesarPassword cp;
	for (string line; getline(read, line); )
	{
		save << cp.encrypt(line) << endl;
		cout << line << endl;
	}
	cout << "���� ��ȣ�� ��ȣȭ�Ͽ����ϴ�." << endl;
	read.close();
	save.close();
	system("pause");

	return 0;
}