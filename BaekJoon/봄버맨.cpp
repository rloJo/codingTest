#include<iostream>
#include <map>
#define X first
#define Y second

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int R, C, N;
string board[202];
map <pair<int,int>,int> bombs;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'O') bombs[{i, j}] = 3;
		}
	}
}

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= R || y >= C;
}

void launch() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] != 'O') {
				bombs[{i, j}] = 3;
				board[i][j] = 'O';
			}
		}
	}
}

void explode() {
	for (auto iter = bombs.begin(); iter != bombs.end(); iter++){
		if (iter->second == 0) {
			int nx = iter->first.X;
			int ny = iter->first.Y;
			board[nx][ny] = '.';
			for (int dir = 0; dir < 4; dir++) {
				nx = iter->first.X + dx[dir];
				ny = iter->first.Y + dy[dir];
				if (OOB(nx, ny)) continue;
				board[nx][ny] = '.';
			}
			iter->second = -1;
		}
	}
}

void Print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
}

void solution() {
	N--; for (auto iter = bombs.begin(); iter != bombs.end(); iter++) iter->second--;
	while (1) {
		if (N <= 0) break;
		N--; for (auto iter = bombs.begin(); iter != bombs.end(); iter++) iter->second--;
		launch();
		if (N <= 0) break;
		N--; for (auto iter = bombs.begin(); iter != bombs.end(); iter++) iter->second--;
		explode();
	}
	Print();
}

int main() {
	init();
	input();
	solution();
}
