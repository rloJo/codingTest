#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int N;
string map[26];
bool vis[26][26];
vector<int> w;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

void bfs(int x, int y){
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
			if (map[nx][ny] == '0') continue;
			Q.push({ nx,ny }); vis[nx][ny] = true;
			wide++;
		}
	}
	w.push_back(wide);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> map[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j] || map[i][j] == '0') continue;
			bfs(i, j);
		}
	}

	sort(w.begin(), w.end());
	
	cout << w.size() << "\n";
	for (auto c : w) cout << c << "\n";

	return 0;
}
