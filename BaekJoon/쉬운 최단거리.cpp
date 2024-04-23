#include <iostream>
#include <queue>
#define X first 
#define Y second
using namespace std;

int n, m;
int map[1002][1002];
int ans[1002][1002];
bool vis[1002][1002];
queue <pair<int, int>> q;
int dx[4] = { 1, 0, -1,0 };
int dy[4] = { 0, 1,0,-1 };

bool OOB(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}

void dfs() {
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (OOB(nx, ny) || vis[nx][ny]) continue;
			if (map[nx][ny] == 0) continue;
			q.push({ nx,ny });
			vis[nx][ny] = true;
			ans[nx][ny] = ans[cur.X][cur.Y] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) {
				q.push({ i,j });
				vis[i][j] = true;
			}
		}
	}
	dfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && vis[i][j] == false)
				ans[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

