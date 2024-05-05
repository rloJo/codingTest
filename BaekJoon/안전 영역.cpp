#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N;
int map[102][102];
bool vis[102][102];
int mx = 0; 
int ans;

bool OOB(int x, int y) {
	return x < 0 || x >= N || y <0 || y >=N;
}

void bfs(int x, int y, int h) {
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || vis[nx][ny]) continue;
			if (map[nx][ny] <= h) continue;
			vis[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			mx = mx < map[i][j] ? map[i][j] : mx;
		}
	}

	for (int i = 0; i <= mx; i++) {
		int result = 0;
		for (int ii = 0; ii < N; ii++) {
			for (int jj = 0; jj < N; jj++) {
				if (map[ii][jj] <= i) continue;
				if (vis[ii][jj]) continue;
				bfs(ii, jj, i);
				result++;
			}
		}

		ans = max(ans, result);

		for (int ii = 0; ii < N; ii++)
			for (int jj = 0; jj < N; jj++)
				vis[ii][jj] = false;
	}

	cout << ans;
	return 0;
}
