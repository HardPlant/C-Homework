#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Leaderboard {
public:
	Leaderboard()
	{
		double score;
		for (int index = 0; index < 10; index++)
		{
			cout << "������ �Է��Ͻÿ� : ";
			cin >> score;
			if (0 <= score && score <= 10)
				scores.push_back(score);
			else
			{
				cout << "���� ���� �ʰ�" << endl;
				index--;
			}
		}
	}
	double getTotal()
	{
		double total = 0;
		sort(scores.begin(), scores.end());
		for (vector<double>::iterator itr = scores.begin() +1 ; itr < scores.end() - 1; itr++)
		{
			total += *itr;
		}
		return total;
	}
private:
	vector<double> scores;
};
int main()
{
	Leaderboard lb;
	cout << "�������� : " << lb.getTotal() << endl;
	return 0;
}