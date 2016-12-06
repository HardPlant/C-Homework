#include <iostream>
#include <vector>
#include <random> // C+11 랜덤 STL 알고리즘
using namespace std;
class Random
{
public:
	Random()
	{
		std::mt19937 generator; // 난수 생성 객체
		generator.seed(random_device()()); // 시드 할당
		uniform_int_distribution<std::mt19937::result_type> rand_num(0, 4000); // 균일 분포 함수에 범위 지정
		while (vect.size() < 100) // 벡터는 크기가 자동으로 조정되므로, 루프 완료 시 크기가 100인 벡터가 됨
		{
			vect.push_back(rand_num(generator)); //균일 분포된 랜덤값을 얻음
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
	cout << "벡터 내의 난수의 짝수의 개수 : " << rand.get_even_count() << endl;
}