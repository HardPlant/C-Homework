#include <iostream>
using namespace std;

class NegativeBalance : public runtime_error // 실행 시에 발견가능한 에러를 담당하는 표준 예외 클래스 상속
{
public:
	NegativeBalance() : runtime_error("NegativeBalance")// runtime_error의 생성자에 넘겨준 문자열은 what()의 return값이 됨
	{
	}
};

class BankAccount
{
public:
	BankAccount()
	{
		cout << "계좌 생성시 입금할 돈은 ? : ";
		cin >> balance;
		cout << "MyAccount 계좌가 생성 되었습니다." << endl;
	}
	void deposit()
	{
		int toDeposit;
		cout << "입금할 금액은? ";
		cin >> toDeposit;
		setBalance(getBalance()+ toDeposit);
		this->display();
	}
	void display()
	{
		cout << "현재 잔액은 : " << getBalance() << endl;
	}
	bool withdraw()
	{
		int toWithdraw;
		cout << "찾을 금액은? ";
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
			cout << e.what() << endl; // 상속한 클래스에 선언된 const char* what() 호출
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