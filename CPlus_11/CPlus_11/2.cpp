#include <iostream>

using namespace std;
class NotFound : public runtime_error
{
public:
	NotFound() : runtime_error("NotFound") // e.what() ��ȯ �� ��Ÿ�� �� ����
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
		cout << "10���� ���ڸ� �Է��Ͽ��� ";
		for (int index = 0; index < 10; index++)
		{
			cin >> arr[index];
		}
		cout << "�迭�� ����� ����..." << endl;

		for (int index = 0; index < 10; index++)
		{
			cout << "[" << arr[index] << "] ";
		}
		cout << endl;
	}
	void find()
	{
		int toFind;
		cout << "ã�� ���� �Է��ϼ��� : ";
		cin >> toFind;
		try
		{
			if (!isinArray(toFind))
				throw NotFound(); // �迭 �ȿ� ���� ������ ���� �߻�
			else
				cout << toFind << "�� �迭�ȿ� �����մϴ�." << endl;
		}
		catch (NotFound e)
		{
			cout << e.what() << endl; // ���ܰ� ������ �ִ� ���� �޽��� ȣ��
		}
	}
	
private:
	bool isinArray(int toFind) // ã�� ���� �迭 ���Ҹ� ���ϴ� ���� �Լ�
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