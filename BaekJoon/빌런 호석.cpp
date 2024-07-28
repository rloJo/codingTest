#include <iostream>
#include <string>

using namespace std;

int N, K, P, X;
int answer = 0;
bool display[11][7] = {
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};
int swapCnt[11][11];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> K >> P >> X;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k < 7; k++) {
				if (display[i][k] != display[j][k]) {
					swapCnt[i][j]++;
				}
			}
		}
	}
}

void solution() {
	for (int i = 1; i <= N; i++) {
		int swap = 0;
		if (i == X) continue;
		int from = X; int to = i;
		int k = K;
		while (k--) {
			swap += swapCnt[from % 10][to % 10];
			from /= 10;
			to /= 10;
		}
		if (swap <= P) answer++;
	}

	cout << answer << "\n";
}

int main() {
	init();
	input();
	solution();
}
