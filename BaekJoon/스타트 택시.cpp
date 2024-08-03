#include <iostream>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

struct client {
	int distance = 0; // 택시부터 출발지 까지 거리
	pair<int, int> st;// 시작 지점
	pair<int, int> ed;// 도착 지점 
	int f = 0; // 출발지 부터 목적지 까지 거리
};

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int N, M, fuel;
int board[22][22];
int dist[22][22];

pair<int, int> taxi;
vector<client> clients;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M >> fuel;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
	cin >> taxi.X >> taxi.Y;
	client c;
	for (int i = 0; i < M; i++) {
		cin >> c.st.X >> c.st.Y >> c.ed.X >> c.ed.Y;
		clients.push_back(c);
	}
}

bool cmp(client a, client b) {
	if (a.distance == b.distance) {
		if (a.st.X != b.st.X) return a.st.X < b.st.X;
		return a.st.Y < b.st.Y;
	}
	return a.distance < b.distance;
}

void init_dist() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = 0;
}

inline bool OOB(int x, int y) {
	return x <= 0 || y <= 0 || x > N || y > N;
}

bool nearest (client &c) {
	init_dist();
	queue<pair<int, int>> Q;
	Q.push(taxi);
	dist[taxi.X][taxi.Y] = 1;
	
	if (taxi == c.st) {
		c.distance = 0;
		return true;
	}

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for(int dir=0; dir<4;dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (dist[nx][ny] > 0) continue;
			if (board[nx][ny] != 0) continue;
			if (nx == c.st.X && ny == c.st.Y) {
				c.distance = dist[cur.X][cur.Y];
				return true;
			}
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}

	c.distance = 10000;
	return false;
}

void calc_fuel(client &c) {
	init_dist();
	queue<pair<int, int>> Q;
	Q.push(c.st);
	dist[c.st.X][c.st.Y] = 1;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (dist[nx][ny] > 0)continue;
			if (board[nx][ny] != 0) continue;
			if (nx == c.ed.X && ny == c.ed.Y) {
				c.f = dist[cur.X][cur.Y];
				return;
			}
			Q.push({ nx,ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
		}
	}
	c.f = -1;
}

void solution() {
	bool flag = true;
	for (int i = 0; i < M; i++) calc_fuel(clients[i]);
	
	for (int i = 0; i < M; i++) {
		if (clients[i].f == -1) {
			cout << "-1";
			return;
		}
	}

	while (1) {
		if (!flag) break;
		flag = false;
		for (int i = 0; i < clients.size(); i++) {
			if (clients[i].distance == 10000) continue;
			if (nearest(clients[i])) flag = true;
		}

		if (flag) {
			sort(clients.begin(), clients.end(), cmp);
			fuel = fuel- clients[0].distance -clients[0].f;
			if (fuel < 0) break;
			fuel += clients[0].f * 2;
			taxi = clients[0].ed;
			clients.erase(clients.begin());
		}
	}

	if (clients.size() > 0) cout << "-1" << "\n";
	else cout << fuel << "\n";
}

int main() {
	init();
	input(); 
	solution();
}
