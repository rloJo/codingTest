#include <iostream>
#include <queue>

#define X first.first
#define Y first.second
#define W second

using namespace std;

int N, M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string map[1002];
int vis[1002][1002][2];
int ans;

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}

int bfs() {
	queue<pair<pair<int, int>,int>> Q;
	Q.push({ { 0,0 },0 }); // x,y좌표 , 벽 부숨 여부
	vis[0][0][0] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		if (cur.X == N - 1 && cur.Y == M - 1) return vis[cur.X][cur.Y][cur.W];
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (nx == N - 1 && ny == M - 1) return vis[cur.X][cur.Y][cur.W] + 1; //출구 도착
			if (map[nx][ny] == '0' && !vis[nx][ny][cur.W]) { 
				vis[nx][ny][cur.W] = vis[cur.X][cur.Y][cur.W] + 1;
				Q.push({ {nx,ny},cur.W });
			}
			if (map[nx][ny] == '1' && !cur.W) {
				vis[nx][ny][1] = vis[cur.X][cur.Y][0] + 1;
				Q.push({ {nx,ny},1 });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	ans = bfs();
	cout << ans;

	return 0;
}
