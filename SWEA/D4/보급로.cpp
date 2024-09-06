#include <iostream>
#include <queue>
#include <string>
#define MAX 100000
#define X first
#define Y second
using namespace std;

int test_case = 0;
int N;
int dx[4] = { 1,0,-1,0};
int dy[4] = { 0,1,0,-1};
vector<string> map;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	map = vector<string>(N);
	for (int i = 0; i < N; i++) cin >> map[i];
}

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= N;
}

int find(int x,int y) {
	vector<vector<int>> vis(N, vector<int>(N, MAX));
	queue <pair<int, int>> Q;
	Q.push({x,y});
	vis[x][y] = 1;

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (vis[nx][ny] <= vis[cur.X][cur.Y] + (map[nx][ny]-'0')) continue;
			Q.push({ nx,ny });
			vis[nx][ny] = vis[cur.X][cur.Y] + (map[nx][ny]-'0');
		}
	}

	return vis[N - 1][N - 1] -1 ;
}

void solution() {
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		input();
		cout << "#" << tc << " " << find(0, 0) << "\n";
	}
}

int main() {
	init();
	solution();
	return 0;
}
