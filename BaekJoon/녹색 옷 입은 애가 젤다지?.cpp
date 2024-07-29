#include <iostream>
#include <queue>

#define X first
#define Y second
#define MAX 987654321

using namespace std;

int N;
int cave[127][127];
int cost[127][127];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void init_cost() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cost[i][j] = MAX;
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cave[i][j];
		}
	}
}

inline bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= N;
}

void BFS() {
	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	cost[0][0] = cave[0][0];
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (cost[nx][ny] <= cost[cur.X][cur.Y] + cave[nx][ny]) continue;
			cost[nx][ny] = cost[cur.X][cur.Y] + cave[nx][ny];
			Q.push({ nx,ny });
		}
	}
}

void solution() {
	int cnt = 1;
	while (1) {
		input();
		if (N == 0) break;
		init_cost();
		BFS();
		cout << "Problem " << cnt++ << ": " << cost[N - 1][N - 1] << "\n";
	}
}

int main() {
	init();
	solution();
}
