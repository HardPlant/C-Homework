#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Queue
{
public:
	Queue()
	{
		currentIndex = -1;
	}
	void display()
	{
		cout << "Queue 삽입 데이터 : ";
		for (int index = 0; index <= currentIndex; index++)
		{
			cout << queue[index];
			if (index != currentIndex)
				cout << ",";
			else
				cout << endl;
		}
	}
	void enqueue(T in)
	{
		if (this->isFull())
			throw runtime_error("큐 범위 초과");
		else
		{
			currentIndex++;
			queue[currentIndex] = in;
		}
	}
	T dequeue()
	{
		if (this->isEmpty())
			throw runtime_error("큐가 비어있음");
		else
		{
			T result = queue[0];
			for(int index=0;index<currentIndex;index++)
			{
				queue[index] = queue[index+1];
			}
			currentIndex--;
			return result;
		}
	}
	bool isEmpty()
	{
		if (currentIndex == -1) return true;
		else return false;
	}
	bool isFull()
	{
		if (currentIndex > 100) return true;
		else return false;
	}
private:
	T queue[100];
	int currentIndex;
};

int main()
{
	Queue<double> queue;
	queue.enqueue(1.4);
	queue.enqueue(4.2);
	queue.enqueue(1.8);
	queue.enqueue(2.6);
	queue.enqueue(4.9);
	queue.display();
	while (!queue.isEmpty())
	{
		cout << "q.dequeue() : " << queue.dequeue() << endl;
	}

}