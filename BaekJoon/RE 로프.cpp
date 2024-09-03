#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> loop;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	loop = vector<int>(N);
	for (int i = 0; i < N; i++) cin >> loop[i];
	sort(loop.begin(), loop.end());
}

void solution() {
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		answer = max(answer, loop[N - i] * i);
	}
	cout << answer;
}

int main() {
	init();
	input();
	solution();
}
