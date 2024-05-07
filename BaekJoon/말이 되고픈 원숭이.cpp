#include <iostream>
#include <queue>

#define X first.first
#define Y first.second
#define Jump second

using namespace std;

int K,H,W;

int dx[4] = { 1,0,-1,0};
int dy[4] = { 0,1,0,-1};

int hx[8] = {2,1,-1,-2,-2,-1,1,2 };
int hy[8] = { 1,2,2,1,-1,-2,-2,-1 };

int map[202][202];
int vis[202][202][32];
int ans;

bool OOB(int x, int y) {
	return x < 0 || x >= H || y < 0 || y >= W;
}

int  bfs() {
	queue<pair<pair<int, int>,int>> Q;
	Q.push({ { 0,0 },0 });
	vis[0][0][0] = 1;
	if (!(W - 1) && !(H - 1)) return 0;
	while (!Q.empty()) {
		auto  cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || map[nx][ny]) continue;
			if (vis[nx][ny][cur.Jump]) continue;
			if (nx == H - 1 && ny == W - 1) return vis[cur.X][cur.Y][cur.Jump];
			vis[nx][ny][cur.Jump] = vis[cur.X][cur.Y][cur.Jump] + 1;
			Q.push({{ nx,ny }, cur.Jump});
		}
		if (cur.Jump < K) {
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + hx[dir];
				int ny = cur.Y + hy[dir];
				if (OOB(nx, ny) || map[nx][ny]) continue;
				if (vis[nx][ny][cur.Jump + 1]) continue;
				if (nx == H - 1 && ny == W - 1) return vis[cur.X][cur.Y][cur.Jump];
				vis[nx][ny][cur.Jump + 1] = vis[cur.X][cur.Y][cur.Jump] + 1;
				Q.push({ { nx,ny }, cur.Jump + 1 });
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> map[i][j];

	ans = bfs();
	cout << ans;

	return 0;
}
