#include <iostream>
#include <queue>

using namespace std;

class info {
public:
	int x = 0; 
	int y = 0;
	int k = 0;
	int len = 0;
	int day;
};

int N, M, K;
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };
string map[1002];
bool vis[12][1002][1002];
int ans;

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}

int bfs() {
	queue<info> Q;
	Q.push({0,0,0,1,1});
	vis[0][0][0] = 1;
	if (N - 1 == 0 && M - 1 == 0) return 1;
	while (!Q.empty()) {
		info cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (OOB(nx,ny)) continue;
			if (nx == N - 1 && ny == M - 1) return cur.len + 1;

			if (map[nx][ny] == '1') {
				if (cur.k == K) continue;
				if (vis[cur.k + 1][nx][ny]) continue;
				if (cur.day == 1) {
					vis[cur.k + 1][nx][ny] = true;
					Q.push({ nx,ny,cur.k + 1,cur.len + 1, cur.day * -1 });
				}
				if (cur.day == -1) {
					Q.push({ cur.x,cur.y,cur.k,cur.len + 1,cur.day * -1 });
				}
			
			}
			else{
				if (vis[cur.k][nx][ny]) continue;
				Q.push({nx,ny,cur.k,cur.len+1,cur.day * -1 });
				vis[cur.k][nx][ny] = true;
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
