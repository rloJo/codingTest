#include <iostream>

using namespace std;

int J, R;
int winner = 0;
int maxScore = 0;
int score[502];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> J >> R;
}

void solution() {
	for (int i = 0; i < J * R; i++) {
		int s;
		cin >> s;
		int idx = i % J + 1;
		score[idx] +=s;
		if (maxScore <= score[idx]) {
			maxScore = score[idx];
			winner = idx;
		}
	}
	cout << winner;
}

int main() {
	init();
	input();
	solution();
}
