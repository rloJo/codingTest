#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N, K, R;
int answer = 0;
map<pair<int, int>, set<pair<int, int>>> road;
vector<pair<int, int>> cow;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N >> K >> R;
	for (int i = 0; i < R; i++) {
		int r, c, nr, nc;
		cin >> r >> c >> nr >> nc;
		road[{r, c}].insert({ nr,nc });
		road[{nr, nc}].insert({ r,c });
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		cow.push_back({ x,y });
	}
}

bool OOB(int x, int y) {
	return x <= 0 || y <= 0 || x > N || y > N;
}

void bfs(int x,int y,int idx) {
	vector<vector<bool>> vis(N+1, vector<bool>(N+1, false));
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	vis[x][y] = true;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx,ny) || vis[nx][ny]) continue;
			if (road.find({cur.X,cur.Y}) != road.end()) {
				if (road[{cur.X, cur.Y}].find({ nx,ny }) != road[{cur.X, cur.Y}].end()) continue;
				else {
					Q.push({ nx,ny });
					vis[nx][ny] = true;
				}
			}
			else {
				Q.push({ nx,ny });
				vis[nx][ny] = true;
			}
		}
	}

	for (int i = idx + 1 ; i < cow.size(); i++) {
		if (vis[cow[i].X][cow[i].Y]) continue;
		answer++;
	}
}

void solution() {
	for (int i = 0; i < cow.size()-1; i++) {
		bfs(cow[i].X, cow[i].Y, i);
	}
	cout << answer;
}

int main() {
	init();
	input();
	solution();
}
