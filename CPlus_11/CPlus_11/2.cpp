#include <iostream>

using namespace std;
class NotFound : public runtime_error
{
public:
	NotFound() : runtime_error("NotFound") // e.what() 반환 시 나타낼 값 설정
	{
	}
};
class SearchArray
{
public:
	SearchArray()
	{
	}
	void input()
	{
		cout << "10개의 숫자를 입력하여라 ";
		for (int index = 0; index < 10; index++)
		{
			cin >> arr[index];
		}
		cout << "배열에 저장된 값은..." << endl;

		for (int index = 0; index < 10; index++)
		{
			cout << "[" << arr[index] << "] ";
		}
		cout << endl;
	}
	void find()
	{
		int toFind;
		cout << "찾을 값을 입력하세요 : ";
		cin >> toFind;
		try
		{
			if (!isinArray(toFind))
				throw NotFound(); // 배열 안에 값이 없으면 예외 발생
			else
				cout << toFind << "은 배열안에 존재합니다." << endl;
		}
		catch (NotFound e)
		{
			cout << e.what() << endl; // 예외가 가지고 있는 에러 메시지 호출
		}
	}
	
private:
	bool isinArray(int toFind) // 찾을 값과 배열 원소를 비교하는 내부 함수
	{
		for (int index = 0; index < 10; index++)
		{
			if (arr[index] == toFind)
				return true;
		}

		return false;
	}
	int arr[10];
};
int main()
{
	SearchArray A;
	A.input();
	A.find();
	return 0;
}