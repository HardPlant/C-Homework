#include <iostream>
#include <string>
#include <map>
using namespace std;
class Dict {
public:
	Dict()
	{

	}
	void menu(int index)
	{
		if (index == 1) return add_voca();
		if (index == 2) return search_voca();
		if (index == 3) return delete_voca();
		if (index == 4) return exit(0);
		else
			cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
	}
	void add_voca()
	{
		string english, korean;
		cout << "�ܾ� �Է� : ";
		cin >> english;
		cout << "�� �Է� : ";
		cin >> korean;
		dict[english] = korean;
		cout << english << "�� �ǹ̴� " << korean << endl;
	}
	void search_voca()
	{
		string english, korean;
		cout << "�ܾ� �Է� : ";
		cin >> english;

		map<string, string>::iterator itr = dict.find(english);
		if (itr == dict.end())
		{
			cout << "ã�� �ܾ �����ϴ�." << endl;
			return;
		}
		else
		{
			korean = itr->second;
			cout << english << "�� �ǹ̴� " << korean << endl;
		}
	}
	void delete_voca()
	{
		string english, korean;
		cout << "�ܾ� �Է� : ";
		cin >> english;
		dict.erase(english);
	}
private:
	map<string, string> dict;
};
int main()
{
	Dict dict;
	while (1)
	{
		int select;
		cout << "1. �ܾ� �߰� 2. �ܾ� �˻� 3. �ܾ� ���� 4. EXIT" << endl;
		cout << endl;
		cout << ">>";
		cin >> select;
		dict.menu(select);
	}
}