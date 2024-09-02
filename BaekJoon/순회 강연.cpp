#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define day first
#define pay second
using namespace std;

int N;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> Q;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	v = vector<pair<int, int>>(N);
	for (int i = 0; i < N; i++) cin >> v[i].pay >> v[i].day;
	sort(v.begin(), v.end());
}

void solution() {
	for (int i = 0; i < N; i++) {
		Q.push(v[i].pay);
		if (Q.size() > v[i].day) Q.pop();
	}
	int answer = 0;
	while (!Q.empty()) {
		answer += Q.top();
		Q.pop();
	}
	cout << answer;
}

int main() {
	init();
	input();
	solution();
}
