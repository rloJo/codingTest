#include <iostream>
#include <vector>
#define X first
#define Y second

using namespace std;

int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

int N;
char school[7][7];

vector<pair<int, int>> teachers;
vector<pair<int, int>> none;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> school[i][j];
			if (school[i][j] == 'T') teachers.push_back({ i,j });
			if (school[i][j] == 'X') none.push_back({ i,j });
		}
	}
}

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= N;
}

bool check() {
	for (auto tea : teachers) {
		for (int dir = 0; dir < 4; dir++) {
			int nx = tea.X;
			int ny = tea.Y;

			while (!OOB(nx, ny)) {
				nx += dx[dir];
				ny += dy[dir];
				if (school[nx][ny] == 'S') {
					return false;
				}
				if (school[nx][ny] == 'O') {
					break;
				}
			}
		}
	}

	return true;
}

void dfs(int idx, int obstacle) {
	if (obstacle == 3) {
		if (check()) {
			cout << "YES";
			exit(0);
		}
		return;
	}
	for (int i = idx; i < none.size(); i++) {
		if (school[none[i].X][none[i].Y] == 'S' || school[none[i].X][none[i].Y] == 'T' || school[none[i].X][none[i].Y] == 'O') continue;
		school[none[i].X][none[i].Y] = 'O';
		dfs(i+1,obstacle + 1);
		school[none[i].X][none[i].Y] = 'X';
	}
}

void solution() {
	dfs(0,0);
	cout << "NO";
}

int main() {
	init();
	input();
	solution();
}
