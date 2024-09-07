#include <iostream>
#include <cmath>
#include <queue>

#define X first
#define Y second
using namespace std;

int test_case;
int N;
vector<vector<int>> room;
vector<vector<bool>> canmove;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> test_case;
}

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

pair<int, int> bfs() {
	int roomnum = 10002;
	int maxCnt = 0;
	int cnt = 1;
	int num = 10002;
	vector<vector<bool>> vis(N, vector<bool>(N, 0));
	queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j]) continue;
			Q.push({ i,j });
			vis[i][j] = 1;
			num = room[i][j];
			cnt = 1;
			while (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (OOB(nx, ny) || vis[nx][ny]) continue;
					if (abs(room[nx][ny] - room[cur.X][cur.Y])!= 1)continue;
					Q.push({ nx,ny });
					vis[nx][ny] = true;
					cnt++;
					if (room[nx][ny] < num) num = room[nx][ny];
				}
			}
			if (maxCnt < cnt) {
				maxCnt = cnt;
				roomnum = num;
			}
			else if (maxCnt == cnt)
			{
				roomnum =min(roomnum, num);
			}
		}
	}

	return {roomnum, maxCnt};
}

void solution() {
	for (int tc = 1; tc <= test_case; tc++) {
		int st = 10000;
		int answer = 0;
		cin >> N;
		room = vector<vector<int>>(N, vector<int>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)cin >> room[i][j];
		}
		pair<int, int> result = bfs();
		cout << "#" << tc << " " << result.first  << " " << result.second << "\n";
	}
}

int main() {
	init();
	input();
	solution();
	return 0;
}
