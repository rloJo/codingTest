#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define X first 

#define Y second
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int M, N;
int cell[502][502];
int answer = 0;
int mx = 0;
int mn = 0;
vector <pair<int, int>> wayPoint;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cell[i][j];
			mx = max(mx, cell[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int stop;
			cin >> stop;
			if(stop==1) wayPoint.push_back({ i,j });
		}
	}
}

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= M || y >= N;
}

bool bfs(int mid) {
	vector<vector<bool>> vis(M, vector<bool>(N, false));
	int mx = 0;
	queue<pair<int,int>> Q;
	Q.push({ wayPoint[0].X, wayPoint[0].Y });
	vis[wayPoint[0].X][wayPoint[0].Y] = true;
	while (!Q.empty()) {
		pair<int,int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || vis[nx][ny]) continue;
			if(abs(cell[cur.X][cur.Y] - cell[nx][ny]) > mid) continue;
			Q.push({ nx,ny });
			vis[nx][ny] = true;
		}
	}
	for (int i = 1; i < wayPoint.size(); i++) {
		if (!vis[wayPoint[i].X][wayPoint[i].Y]) return false;
	}
	return true;
}

void solution() {
	while (mn <= mx) {
		int mid = (mx + mn) / 2;
		if (bfs(mid)) {
			answer = mid;
			mx = mid - 1;
		}
		else mn = mid + 1;
	}
	cout << answer;
}

int main() {
	init();
	input();
	solution();
}
