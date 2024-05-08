#include <iostream>
#include <queue>

#define X first.first
#define Y first.second
#define Wall second

using namespace std;

int N, M, K;
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };
string map[1002];
int vis[12][1002][1002];
int ans;

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}

int bfs() {
	queue<pair<pair<int, int>, int>> Q;
	Q.push({ { 0, 0 },0 });
	vis[0][0][0] = 1;
	if (N - 1 == 0 && M - 1 == 0) return 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx,ny)) continue;
			if (nx == N - 1 && ny == M - 1) return vis[cur.Wall][cur.X][cur.Y] + 1;
			if (map[nx][ny] == '1') {
				if (cur.Wall == K) continue;
				if (vis[cur.Wall + 1][nx][ny]) continue;
				Q.push({ {nx,ny},cur.Wall + 1 });
				vis[cur.Wall + 1][nx][ny] = vis[cur.Wall][cur.X][cur.Y] + 1;
			}
			else{
				if (vis[cur.Wall][nx][ny]) continue;
				Q.push({ {nx,ny},cur.Wall });
				vis[cur.Wall][nx][ny] = vis[cur.Wall][cur.X][cur.Y] + 1;
			}
			
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	ans = bfs();

	cout << ans;
	return 0;
}
