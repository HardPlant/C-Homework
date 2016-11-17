#include <iostream>
using namespace std;

class NegativeBalance : public runtime_error // ���� �ÿ� �߰߰����� ������ ����ϴ� ǥ�� ���� Ŭ���� ���
{
public:
	NegativeBalance() : runtime_error("NegativeBalance")// runtime_error�� �����ڿ� �Ѱ��� ���ڿ��� what()�� return���� ��
	{
	}
};

class BankAccount
{
public:
	BankAccount()
	{
		cout << "���� ������ �Ա��� ���� ? : ";
		cin >> balance;
		cout << "MyAccount ���°� ���� �Ǿ����ϴ�." << endl;
	}
	void deposit()
	{
		int toDeposit;
		cout << "�Ա��� �ݾ���? ";
		cin >> toDeposit;
		setBalance(getBalance()+ toDeposit);
		this->display();
	}
	void display()
	{
		cout << "���� �ܾ��� : " << getBalance() << endl;
	}
	bool withdraw()
	{
		int toWithdraw;
		cout << "ã�� �ݾ���? ";
		cin >> toWithdraw;
		try
		{
			if (balance < toWithdraw)
				throw NegativeBalance();
			
			setBalance(getBalance() - toWithdraw);

			this->display();
		}
		catch (NegativeBalance e)
		{
			//cout << "NegativeBalance" << endl;
			cout << e.what() << endl; // ����� Ŭ������ ����� const char* what() ȣ��
		}

	}
	void setBalance(int b)
	{
		this->balance = b;
	}
	int getBalance()
	{
		return balance;
	}
private:
	int balance;
};

int main()
{
	BankAccount A;
	A.deposit();
	A.withdraw();

	return 0;
}