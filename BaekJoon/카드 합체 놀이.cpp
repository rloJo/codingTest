#include <iostream>
#include <queue>

using namespace std;

int n, m;
priority_queue<long long,vector<long long>,greater<long long>> nums;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		nums.push(num);
	}
}

void solution() {
	for (int i = 1; i <= m; i++) {
		long long num1 = nums.top(); nums.pop();
		long long num2 = nums.top(); nums.pop();
		nums.push(num1+num2);
		nums.push(num1+num2);
	}
	
	long long answer = 0;
	while (!nums.empty()) {
		answer += nums.top();
		nums.pop();
	}
	cout << answer;
}

int main() {
	init();
	input();
	solution();
}
