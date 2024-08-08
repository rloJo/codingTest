#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };


int circle[52][52];
bool vis[52][52] = { false };

int N, M, T;
int x[52], d[52], k[52];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> circle[i][j];
		}
	}
	for (int i = 1; i <= T; i++) {
		cin >> x[i] >> d[i] >> k[i];
	}
}

void spin(int order) {
	if (d[order] == 0) {
		for (int i = x[order]; i <= N; i += x[order]) {
			for (int s = 1; s <= k[order]; s++) {
				for (int j = M; j > 1; j--) {
					swap(circle[i][j], circle[i][j - 1]);
				}
			}
		}
	}
	else {
		for (int i = x[order]; i <= N; i += x[order]) {
			for (int s = 1; s <= k[order]; s++) {
				for (int j = 1; j < M; j++) {
					swap(circle[i][j], circle[i][j + 1]);
				}
			}
		}
	}
}

void init_vis() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			vis[i][j] = false;
		}
	}
}

bool DFS(int x,int y) {
	int standard = circle[x][y];
	init_vis();
	bool flag = false;
	queue<pair<int, int>> Q;
	Q.push({ x,y });             
	vis[x][y] = true;			 
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
 			int ny = cur.Y + dy[dir]; 
			if (ny == 0) ny = M;
			if (ny == M + 1) ny = 1;
			if (nx <= 0 || nx > N) continue;
			if (vis[nx][ny]) continue;
			if (circle[nx][ny] != standard) continue;
			flag = true;
			circle[nx][ny] = 0;
			Q.push({ nx,ny });
			vis[nx][ny] = true;
		}
	}

	if(flag) circle[x][y] = 0;
	return flag;
}


bool deleteNum() {

	bool flag = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (circle[i][j] == 0) continue;
			if(DFS(i,j)) flag = true;
		}
	}
	return flag;
}

void averageSet() {
	int zeroCnt = 0;
	float avg = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (circle[i][j] == 0) zeroCnt++;
			avg += circle[i][j];
		}
	}
	if (zeroCnt == N * M) return;
	avg /= (N*M - zeroCnt);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (circle[i][j] == 0) continue;
			if (circle[i][j] > avg) circle[i][j]--;
			else if (circle[i][j] < avg) circle[i][j]++;
		}
	}
}

int calcScore() {
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			answer += circle[i][j];
		}
	}
	return answer;
}

void solution() {
	for(int i=1;i<=T;i++) {
		spin(i);
		if (deleteNum())continue;
		averageSet();
		
	}
	cout << calcScore() << "\n";
}

int main() {
	init();
	input();
	solution();
}
