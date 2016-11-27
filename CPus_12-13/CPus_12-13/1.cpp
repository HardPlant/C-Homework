//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename T>
//class Queue
//{
//public:
//	Queue()
//	{
//		currentIndex = -1;
//	}
//	void streamEnqueue()
//	{
//		string input;
//		string delimiter = ",";
//		int toEnqueue;
//		int position;
//		cin >> input;
//		while ((position = input.find(delimiter)) != string::npos)
//		{
//			toEnqueue = stoi((input.substr(0, position)));
//			cout << toEnqueue << ' ';
//			this->enqueue(toEnqueue);
//			input.erase(0, position + delimiter.length());
//			cout << endl;
//		}
//	}
//	void enqueue(T in)
//	{
//		if (this->isFull())
//			throw runtime_error("ť ���� �ʰ�");
//		else
//		{
//			currentIndex++;
//			queue[currentIndex] = in;
//		}
//	}
//	T dequeue()
//	{
//		if (this->isEmpty())
//			throw runtime_error("ť�� �������");
//		else
//		{
//			T result = queue[currentIndex];
//			currentIndex--;
//			return result;
//		}
//	}
//	bool isEmpty()
//	{
//		if (currentIndex == -1) return true;
//		else return false;
//	}
//	bool isFull()
//	{
//		if (currentIndex > 100) return true;
//		else return false;
//	}
//private:
//	T queue[100];
//	int currentIndex;
//};
//
//int main()
//{
//	Queue<int> queue;
//	cout << "Queue ���� ������ : ";
//	queue.streamEnqueue();
//	while (!queue.isEmpty())
//	{
//		cout << "q.dequeue() : " << queue.dequeue() << endl;
//	}
//
//}