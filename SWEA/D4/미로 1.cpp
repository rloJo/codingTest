#include <iostream>
#include <string>
#include <queue>
#define ROW 16
#define COL 16
#define X first
#define Y second
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<string> map;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	int test_case;
	cin >> test_case;
	map = vector<string>(ROW);
	for (int i = 0; i < ROW; i++) cin >> map[i];
}

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= ROW || y >= COL;
}

bool bfs() {
	vector<vector<bool>> vis(ROW, vector<bool>(COL, false));
	queue<pair<int, int>> Q;
	Q.push({ 1,1 });
	vis[1][1] = true;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || vis[nx][ny]) continue;
			if (map[nx][ny]-'0' ==1) continue;
			if (map[nx][ny] -'0' == 3) return true;
			Q.push({ nx,ny });
			vis[nx][ny] = true;
		}
	}
	return false;
}

void solution() {
	for (int tc = 1; tc <= 10; tc++) {
		input();
		cout << "#" << tc << " " << bfs() << "\n";
	}
}

int main() {
	init();
	solution();
	return 0;
}
