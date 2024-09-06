#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int ladder[102][102];
int test_case = 0;
		// 왼 오 아
int dx[3] = { 0,0,1 };
int dy[3] = { -1,1,0 };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> test_case;
	for (int r = 0; r < 100; r++) {
		for (int c = 0; c < 100; c++) cin >> ladder[r][c];
	}
}
bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= 100 || y >= 100;
}

bool check(int idx) {
	vector<vector<bool>> vis(100, vector<bool>(100, false));
	queue <pair<int, int>> Q;
	Q.push({ 0,idx });
	vis[0][idx] = true;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		if (ladder[cur.X][cur.Y] == 2) return true;
		for (int dir = 0; dir < 3; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || vis[nx][ny]) continue;
			if (ladder[nx][ny] == 0) continue;
			Q.push({ nx,ny });
			vis[nx][ny] = true;
			break;
		}
	}
	return false;
}

void solution() {
	for (int tc = 1; tc <= 10; tc++) {
		input();
		for (int i = 0; i < 100; i++) {
			if (ladder[0][i] == 1) {
				if (check(i)) cout << "#" << tc << " " << i << "\n";
			}
		}
	}
}

int main() {
	init();
	solution();
	return 0;
}
