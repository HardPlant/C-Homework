#include <iostream>
#include <vector>
#include <random> // C+11 ���� STL �˰���
using namespace std;
class Random
{
public:
	Random()
	{
		std::mt19937 generator; // ���� ���� ��ü
		generator.seed(random_device()()); // �õ� �Ҵ�
		uniform_int_distribution<std::mt19937::result_type> rand_num(0, 4000); // ���� ���� �Լ��� ���� ����
		while (vect.size() < 100) // ���ʹ� ũ�Ⱑ �ڵ����� �����ǹǷ�, ���� �Ϸ� �� ũ�Ⱑ 100�� ���Ͱ� ��
		{
			vect.push_back(rand_num(generator)); //���� ������ �������� ����
		}
	}
	int get_even_count()
	{
		int count = 0;
		vector<int>::iterator itr;
		for (itr = vect.begin(); itr < vect.end(); itr++)
		{
			if ((*itr) % 2 == 0) count++;
		}
		return count;
	}
private:
	vector<int> vect;
};
int main()
{
	Random rand;
	cout << "���� ���� ������ ¦���� ���� : " << rand.get_even_count() << endl;
}