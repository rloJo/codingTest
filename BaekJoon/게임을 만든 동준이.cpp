#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> score;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	score = vector<int>(N);
	for (int i = 0; i < N; i++) cin >> score[i];
}

void solution() {
	int answer = 0;
	for (int i = N-2; i >= 0; i--) {
		if (score[i] >= score[i+1]) {
			answer += score[i] - score[i+1] + 1;
			score[i] = score[i+1]-1;
		}
	}
	cout << answer;
}

int main() {
	init();
	input();
	solution();
}
