#include <iostream>
/*
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 여덟 가지이다.
push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 
	만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 
	만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 
	만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다.
	만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.


첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
	주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
문제에 나와있지 않은 명령이 주어지는 경우는 없다.
*/
using namespace std;

class dequeue {

private:
	int* data;
	int head;
	int tail;

public:
	dequeue();
	dequeue(int N);
	~dequeue();
	int pop_front();
	int pop_back();
	void push_front(int x);
	void push_back(int x);
	bool empty();
	int size();
	int front();
	int back();
};

dequeue::dequeue() {
	data = new int[10];
	head = 5;
	tail = 5;
}

dequeue::dequeue(int N) {
	data = new int[2*N+1];
	head = N;
	tail = N+1;
}

dequeue::~dequeue() {
	delete[] data;
}

int dequeue::pop_front() {
	if (empty())
		return -1;
	else 
	{
		return data[++head];
	}
	
}

int dequeue::pop_back() {
	if (empty())
		return -1;
	else
	{
		return data[--tail];
	}

}

void dequeue::push_front(int x) {
	data[head--] = x;
}

void dequeue::push_back(int x) {
	data[tail++] = x;
}

int dequeue::front() {
	if (this->empty())
		return -1;
	else
		return data[head+1];
}

int dequeue::back() {
	if (this->empty())
		return -1;
	else
		return data[tail-1];
}

bool dequeue::empty() {
	if (tail- head ==1)
		return true;
	else
		return false;
}


int dequeue::size() {
	return tail-head-1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N; string str; int tmp;
	cin >> N;
	dequeue dq(N);
	while (N--) {
		cin >> str;
		if (str == "push_front") {
			cin >> tmp;
			dq.push_front(tmp);
		}
		else if (str == "push_back") {
			cin >> tmp;
			dq.push_back(tmp);
		}
		else if (str == "pop_front") {
			cout << dq.pop_front() << "\n";
		}
		else if (str == "pop_back") {
			cout << dq.pop_back() << "\n";
		}
		else if (str == "size") {
			cout << dq.size() << "\n";
		}
		else if (str == "empty") {
			cout << dq.empty() << "\n";
		}
		else if (str == "front") {
			cout << dq.front() << "\n";
		}
		else if (str == "back") {
			cout << dq.back() << "\n";
		}

	}

	return 0;
}
