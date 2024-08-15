#include <iostream>

using namespace std;

int N;
int room[17][17];
int answer;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> room[i][j];
	}
}

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= N;
}

// shape
/*
	0 => 가로
	1 => 대각선
	2 => 세로
*/
bool condition(int shape, int x, int y) {
	if (shape == 0)
		return OOB(x, y + 1) || room[x][y + 1] == 1;

	if (shape == 1)
		return OOB(x, y + 1) || OOB(x + 1, y) || OOB(x + 1, y + 1) || room[x][y + 1] == 1 || room[x + 1][y] == 1 || room[x + 1][y + 1] == 1;

	if (shape == 2)
		return OOB(x + 1, y) || room[x + 1][y] == 1;
}

void dfs(int shape, int x,int y) {
	if (x == N - 1 && y == N - 1) {
		answer++;
		return;
	}

	if (shape == 0) {
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				if (condition(i,x,y)) continue;
				dfs(i,x,y+1);
			}
			if (i == 1) {
				if (condition(i, x, y)) continue;
				dfs(i, x+1, y + 1);
			}
		}
	}

	if (shape == 1) {
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				if (condition(i, x, y)) continue;
				dfs(i, x, y + 1);
			}

			if (i == 1) {
				if (condition(i, x, y)) continue;
				dfs(i, x + 1, y + 1);
			}

			if (i == 2) {
				if (condition(i, x, y)) continue;
				dfs(i, x + 1, y);
			}
		}

	}

	if(shape ==2){
		for (int i = 1; i < 3; i++) {
			if (i == 1) {
				if (condition(i, x, y)) continue;
				dfs(i, x + 1, y + 1);
			}
			if (i == 2) {
				if (condition(i, x, y)) continue;
				dfs(i, x + 1, y);
			}
		}
	}
}

void solution() {
	dfs(0,0,1);
	cout << answer << "\n";
}

int main() {
	init();
	input();
	solution();
}
