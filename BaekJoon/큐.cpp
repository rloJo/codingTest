#include <iostream>
/*
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 여섯 가지이다.
push X : 정수 X를 큐에 넣는 연산이다.
pop : 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.
	만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
size : 큐에 들어있는 정수의 개수를 출력한다.
empty : 큐가 비어있으면 1, 아니면 0을 출력한다.
front : 큐의 가장 앞에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
back : 큐의 가장 뒤에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
*/
using namespace std;

class queue {

private:
	int* data;
	int head;
	int tail;

public:
	queue();
	queue(int N);
	~queue();
	int pop();
	void push(int x);
	bool empty();
	int size();
	int front();
	int back();
};

queue::queue() {
	data = new int[10];
	head = 0;
	tail = 0;
}

queue::queue(int N) {
	data = new int[N];
	head = 0;
	tail = 0;
}

queue::~queue() {
	delete[] data;
}

int queue::pop() {
	if (empty())
		return -1;
	else 
	{
		return data[head++];
	}
	
}

void queue::push(int x) {
	data[tail++] = x;
}

int queue::front() {
	if (this->empty())
		return -1;
	else
		return data[head];
}

int queue::back() {
	if (this->empty())
		return -1;
	else
		return data[tail-1];
}

bool queue::empty() {
	if (head==tail)
		return true;
	else
		return false;
}


int queue::size() {
	return tail-head;
}



int main() {
	int T;
	cin >> T;
	string str = "";
	int num = 0;
	queue Q(T);
	while (T--) {
		cin >> str;
		if (str == "push")
		{
			cin >> num;
			Q.push(num);
		}
		else if (str == "pop")
		{
			cout << Q.pop() << "\n";
		}
		else if (str == "front")
		{
			cout << Q.front() << "\n";
		}
		else if (str == "back")
		{
			cout << Q.back() << "\n";
		}
		else if (str == "size")
		{
			cout << Q.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << Q.empty() << "\n";
		}
	
	}

	return 0;
}
