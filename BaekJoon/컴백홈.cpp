#include <iostream>
#include <string>
#include <vector>
#define X first
#define Y second

using namespace std;

struct info {
	int x;
	int y;
	int length;
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int R, C, K;
int answer;
vector<string> road;
bool vis[6][6];
pair<int, int> hansu;
pair<int, int> home;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		string info;
		cin >> info;
		road.push_back(info);
	}
	home = { 0,C - 1 };
	hansu = { R - 1,0 }; 
}

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= R || y >= C;
}

void DFS(int x, int y, int cnt) {
	if (cnt == K) {
		if (home.X == x && home.Y == y) answer++;
		return;
	}

	vis[x][y] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (vis[nx][ny]|| OOB(nx,ny)) continue;
		if (road[nx][ny] == 'T') continue;
		DFS(nx, ny, cnt + 1);
		vis[nx][ny] = false;
	}
}

void solution() {
	DFS(hansu.X, hansu.Y,1);
	cout << answer;
}

int main() {
	init();
	input();
	solution();
}
