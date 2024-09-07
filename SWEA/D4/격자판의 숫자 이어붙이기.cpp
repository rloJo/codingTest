
#include <iostream>
#include <queue>
#include <unordered_set>
#include <cmath>

using namespace std;

int test_case;
int board[4][4];
int N;
unordered_set<int> outcome;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct info {
	int x;
	int y;
	int cnt;
	int num;
};

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> test_case;
}

bool OOB(int x, int y) {
	return x < 0 || x >= 4 || y < 0 || y >= 4;
}

void bfs(int x,int y) {
	queue<info> Q;
	Q.push({ x,y,0,board[x][y]});
	while (!Q.empty()) {
		info cur = Q.front(); Q.pop();
		if (cur.cnt == 6) {
			outcome.insert(cur.num);
			continue;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (OOB(nx, ny)) continue;
			int newNum = cur.num + board[nx][ny] * pow(10, cur.cnt + 1);
			Q.push({ nx, ny, cur.cnt + 1, newNum });
		}
	}
}

void solution() {
	for (int tc = 1; tc <= test_case; tc++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) cin >> board[i][j];
		}
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) bfs(i, j);
		}

		cout << "#" << tc << " " << outcome.size() << "\n";
		outcome.clear();
	}
}

int main() {
	init();
	input();
	solution();
	return 0;
}
