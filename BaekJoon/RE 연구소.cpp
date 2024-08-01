#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;
int board[9][9];
bool vis[9][9];
int answer;
vector<pair<int, int>> virus;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) virus.push_back({ i,j });
		}
	}
}

void init_vis() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			vis[i][j] = false;
		}
	}
}

inline bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= M;
}

int calcSafezone() {
	int safeZone = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0 && !vis[i][j]) safeZone++;
		}
	}

	return safeZone;
}

int bfs() {
	init_vis();

	queue<pair<int, int>> Q;
	for (pair<int, int> v : virus) Q.push(v);

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		vis[cur.X][cur.Y] = true;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir]; 
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (vis[nx][ny]) continue;
			if (board[nx][ny] != 0) continue;
			Q.push({ nx,ny });
			vis[nx][ny] = true;
		}
	}

	return calcSafezone();
}

void dfs(int wall) {

	if (wall == 3) {
		answer = max(answer, bfs());
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] > 0) continue;
			board[i][j] = 1;
			dfs(wall + 1);
			board[i][j] = 0;
		}
	}
}

void solution() {
	dfs(0);
	cout << answer << "\n";
}

int main() {
	init();
	input(); 
	solution();
}
