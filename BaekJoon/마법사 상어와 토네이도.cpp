#include <iostream>
#define X first
#define Y second

using namespace std;

int N;
int A[502][502];
int answer = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int d = 0;
int dust[5][5] = {
	{0,0,2,0,0 },
	{0,10,7,1,0,},
	{5,-1,0,0,0},
	{0,10,7,1,0},
	{0,0,2,0,0}
};

pair<int, int> cur;

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= N;
}


void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	}
	cur.X = N / 2;
	cur.Y = N / 2;
}

void turn() {
	int tmp[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmp[i][j] = dust[j][4 - i];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dust[i][j] = tmp[i][j];
		}
	}

	d++;
	d %= 4;
}

void  move(int dir) {
	while(d!=dir) turn();
	pair<int, int> alpha;
	int dustCnt = A[cur.X][cur.Y];
	for (int i = -2; i < 3; i++) {
		for (int j = -2; j < 3; j++) {
			if (dust[2+i][2+j] == 0) continue;
			if (dust[2+i][2+j] == -1) {
				alpha = { cur.X +i, cur.Y + j };
				continue;
			}
			int dustRatio = (int)((A[cur.X][cur.Y] * dust[2 + i][2 + j]) / 100);
			dustCnt -= dustRatio;
			if (OOB(cur.X + i, cur.Y + j)) {
				answer += dustRatio;
				continue;
			}
			A[cur.X + i][cur.Y + j] += dustRatio;
		}
	}
	A[cur.X][cur.Y] = 0;

	if (OOB(alpha.X, alpha.Y)) {
		answer += dustCnt;
		return;
	}

	A[alpha.X][alpha.Y] += dustCnt;
}

void solution() {
	int col = 1; // 이동 칸 수
	int cnt = 2; // 칸 횟수
	int dir = 0; // 방향 
	while (1){
		dir = dir % 4;
		if (cnt == 0) {
			cnt = 2;
			col++;
		}
		for (int i = 0; i < col; i++) {
			if (cur.X == 0 && cur.Y == 0) return;
			cur.X += dx[dir];
			cur.Y += dy[dir];
			move(dir);
		}

		cnt--;
		dir++;
	}
}

int main() {
	init();
	input();
	solution();
	cout << answer << "\n";
}
