#include <iostream>

using namespace std;

int M, N;
int worm[702][702];
int grow[3];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> M >> N;
}

void Print() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) cout << worm[i][j] + 1 << " ";
		cout << "\n";
	}
}

void wormSelfGrow() {
	int idx = 0;
	for (int i = M - 1; i >= 0; i--) {
		while (grow[idx] <= 0) idx++;
		worm[i][0] += idx;
		grow[idx]--;
	}

	for (int i = 1; i < M; i++) {
		while (grow[idx] <= 0) idx++;
		worm[0][i] += idx;
		grow[idx]--;
	}
}

void wormGrow() {
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < M; j++) {
			worm[i][j] = worm[i - 1][j];
		}
	}
}

void solution() {
	for (int i = 0; i < N; i++) {
		cin >> grow[0] >> grow[1] >> grow[2];
		wormSelfGrow();
	}
	wormGrow();
	Print();
}

int main() {
	init();
	input();
	solution();
}
