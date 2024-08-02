#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int N;
int board[22][22];
int dist[22][22];
int answer;

pair<int, int> shark;
int sharkWeight;
int atenFish;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	sharkWeight = 2;
	atenFish = 0;
	answer = 0;
	cin >> N ;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				shark = { i,j };
				board[i][j] = 0;
			}
		}
	}
}

void init_dist() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dist[i][j] = 0;
}

inline bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= N;
}

bool bfs() {
	int distance = 10000;
	pair<int, int> food;
	queue<pair<int, int>> Q;

	init_dist();
	Q.push(shark);
	dist[shark.X][shark.Y] = 1;

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for(int dir=0; dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (dist[nx][ny] > 0) continue;
			if (board[nx][ny] > sharkWeight) continue;
			if (1 <= board[nx][ny] && board[nx][ny] < sharkWeight) {
				if (distance > dist[cur.X][cur.Y]) {
					distance = dist[cur.X][cur.Y];
					food = { nx,ny };
				}
				else if (distance == dist[cur.X][cur.Y]) {
					if (food.X > nx)
						food = { nx,ny };
					else if (food.X == nx)
						food.Y = min(food.Y, ny);
				}
			}
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}

	if (distance == 10000) return false;

	shark = food;
	atenFish++;
	if (atenFish == sharkWeight) {
		sharkWeight++;
		atenFish = 0;
	}
	board[food.X][food.Y] = 0;
	answer += distance;
	return true;
}

void solution() {
	while (bfs());
	cout << answer << "\n";
}

int main() {
	init();
	input(); 
	solution();
}
