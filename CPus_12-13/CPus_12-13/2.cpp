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
	cout << "읽어올 파일은?";
	cin >> toRead;
	cout << "저장할 파일은?";
	cin >> toSave;

	ifstream read;
	ofstream save;
	
	read.open(toRead);
	save.open(toSave);
	if (read.fail() || save.fail())
	{
		cout << "파일 읽기에 실패했습니다." << endl;
		return -1;
	}
	CaesarPassword cp;
	for (string line; getline(read, line); )
	{
		save << cp.encrypt(line) << endl;
		cout << line << endl;
	}
	cout << "시저 암호로 암호화하였습니다." << endl;
	read.close();
	save.close();
	system("pause");

	return 0;
}