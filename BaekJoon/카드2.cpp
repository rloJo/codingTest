#include <iostream>
/*
N장의 카드가 있다. 
각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있으며, 
1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.
이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다. 
우선, 제일 위에 있는 카드를 바닥에 버린다.
그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.
예를 들어 N=4인 경우를 생각해 보자. 카드는 제일 위에서부터 1234 의 순서로 놓여있다.
1을 버리면 234가 남는다.
여기서 2를 제일 아래로 옮기면 342가 된다. 3을 버리면 42가 되고, 4를 밑으로 옮기면 24가 된다. 
마지막으로 2를 버리고 나면, 남는 카드는 4가 된다.
N이 주어졌을 때, 제일 마지막에 남게 되는 카드를 구하는 프로그램을 작성하시오.

첫째 줄에 정수 N(1 ≤ N ≤ 500,000)이 주어진다.
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	queue Q(2*N); //선형큐 이기 때문에 overhead 방지로 2N 크기 설정
	for (int i = 1; i <= N; i++)
		Q.push(i);

	while (1)
	{	
		if (Q.size() == 1) //사이클을 돌고 q size가 1이면 정지
			break;
		Q.pop();
		if (Q.size() <= 2) //카드를 버리고 q size가 2이면 정지
			break;
		Q.push(Q.pop());
	}

	cout << Q.pop(); // 정지 되었을 때 pop하면 정답 출력
	return 0;
}
