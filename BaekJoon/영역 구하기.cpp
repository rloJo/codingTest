#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int N, M, K;
bool vis[102][102];
int ans;
vector<int> w;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}

void bfs(int x,int y){
	int wide = 0;
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	vis[x][y] = true;
	wide++;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); 
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (OOB(nx, ny) || vis[nx][ny]) continue;
			Q.push({ nx,ny }); vis[nx][ny] = true;
			wide++;
		}
	}
	w.push_back(wide);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x2-1; i >= x1; i--) {
			for (int j = y2 - 1; j >= y1; j--) {
				vis[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vis[i][j]) continue;
			bfs(i, j);
			ans++;
		}
	}
	sort(w.begin(), w.end());
	
	cout << ans << "\n";
	for (auto c : w) cout << c << " ";

	return 0;
}
