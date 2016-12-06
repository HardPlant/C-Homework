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
			cout << "입력이 잘못되었습니다." << endl;
	}
	void add_voca()
	{
		string english, korean;
		cout << "단어 입력 : ";
		cin >> english;
		cout << "뜻 입력 : ";
		cin >> korean;
		dict[english] = korean;
		cout << english << "의 의미는 " << korean << endl;
	}
	void search_voca()
	{
		string english, korean;
		cout << "단어 입력 : ";
		cin >> english;

		map<string, string>::iterator itr = dict.find(english);
		if (itr == dict.end())
		{
			cout << "찾는 단어가 없습니다." << endl;
			return;
		}
		else
		{
			korean = itr->second;
			cout << english << "의 의미는 " << korean << endl;
		}
	}
	void delete_voca()
	{
		string english, korean;
		cout << "단어 입력 : ";
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
		cout << "1. 단어 추가 2. 단어 검색 3. 단어 삭제 4. EXIT" << endl;
		cout << endl;
		cout << ">>";
		cin >> select;
		dict.menu(select);
	}
}