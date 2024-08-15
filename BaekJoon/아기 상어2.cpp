#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int N, M;
int state[52][52];
int vis[52][52];
int answer = 0;


void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> state[i][j];
		}
	}
}

void init_vis() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			vis[i][j] = 0;
		}
	}
}

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= M;
}

void find_safe(pair<int,int> spot) {
	queue<pair<int, int>> Q;
	Q.push({ spot.X,spot.Y });
	vis[spot.X][spot.Y] = 1;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (vis[nx][ny] > 0) continue;
			if (state[nx][ny] == 1) {
				answer = max(answer, vis[cur.X][cur.Y]);
				return;
			}
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
}

void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (state[i][j] == 1) continue;
			init_vis();
			find_safe({i,j});
		}
	}
	cout << answer << "\n";
}

int main() {
	init();
	input();
	solution();
}
