#include <iostream>
#include <queue>
#include <vector>
#include <climits>

#define X first
#define Y second

using namespace std;

int N;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int map[102][102];
int vis[102][102];
vector<pair<int,int>> land[10002];
int ans = INT_MAX;

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

void bfs(int x, int y, int num) {
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	vis[x][y] = 1;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || vis[nx][ny]) continue;
			if (map[nx][ny] == 0) {
				land[num].push_back({ cur.X,cur.Y });
				continue;
			}
			Q.push({nx,ny});
			vis[nx][ny] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N ;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	int num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!map[i][j]) continue;
			if (vis[i][j]) continue;
			bfs(i, j, num++);
		}
	}

	for (int i = 1; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			for (auto A : land[i]) {
				for (auto B : land[j]) {
					ans = min(abs(A.X - B.X) + abs(A.Y - B.Y) - 1, ans);
				}
			}
		}
	}

	cout << ans;

	return 0;
}
