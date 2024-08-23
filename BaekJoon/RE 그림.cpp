#include <iostream>
#include <queue>
#define X first 
#define Y second
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n, m;
int picture[502][502];
int vis[502][502];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}


void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> picture[i][j];
		}
	}
}

int BFS(int x, int y) {
	int cnt = 1;
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	vis[x][y]= true;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (vis[nx][ny]) continue;
			if (picture[nx][ny] == 0) continue;
			Q.push({ nx,ny });
			cnt++;
			vis[nx][ny] = true;
		}
	}
	return cnt;
}

void solution() {
	int picSize = 0, picCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || picture[i][j] == 0) continue;
			picCnt++;
			picSize = max(picSize,BFS(i, j));
		}
	}
	cout << picCnt << "\n";
	cout << picSize << "\n";
}

int main() {
	init();
	input();
	solution();
}
