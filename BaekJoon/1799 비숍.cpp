#include <iostream>
using namespace std;

int N;
int answer[2];
bool canDrop[12][12];
bool isused1[30];
bool isused2[30];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> canDrop[i][j];
	}
}


void tracking(int x, int y, int cnt, int color) {
	if (y >= N) {
		x++;
		if (y % 2 == 0) y = 1;
		else y = 0;
	}

	if (x >= N) {
		answer[color] = max(answer[color], cnt);
		return;
	}

	if (canDrop[x][y] && !isused1[x + y] && !isused2[y - x + N - 1]) {
		isused1[x + y] = true;
		isused2[y - x + N - 1] = true;
		tracking(x, y + 2, cnt + 1, color);
		isused1[x + y] = false;
		isused2[y - x + N - 1] = false;
	}

	tracking(x, y + 2, cnt, color);
}

void solution() {
	tracking(0, 0, 0,0);
	tracking(0, 1, 0,1);
	cout << answer[0] + answer[1];
}

int main() {
	init();
	input();
	solution();
}
