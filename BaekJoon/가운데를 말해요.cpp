#include <iostream>
#include <queue>
#include <functional>

using namespace std;
priority_queue<int,vector<int>,less<int>> max_q;
priority_queue<int,vector<int>,greater<int>> min_q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int num;
	cin >> N;
	while (N--) {
		cin >> num;
		if (max_q.empty()) max_q.push(num);
		else if (max_q.size() == min_q.size()) max_q.push(num);
		else min_q.push(num);

		if (!max_q.empty() && !min_q.empty() && !(max_q.top() <= min_q.top())) {
			int tmp = max_q.top();
			max_q.pop(); max_q.push(min_q.top());
			min_q.pop(); min_q.push(tmp);
		}
		
		cout << max_q.top() << "\n";
	}
}
