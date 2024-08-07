#include <iostream>
#include <vector>
#include <cmath>

#define X first 
#define Y second
using namespace std;

struct Fireball {
	int r;
	int c;
	int m;
	int s;
	int d;
};

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

int dirCo[4] = {0,2,4,6};
int dirCx[4] = {1,3,5,7};

int N, M, K;
vector<Fireball> board[52][52];


void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		Fireball fb;
		cin >> fb.r >> fb.c >> fb.m >> fb.s >> fb.d;
		board[fb.r][fb.c].push_back(fb);
	}
}

void copyBoard(vector<Fireball> tmp[52][52]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			board[i][j] = tmp[i][j];
			if (board[i][j].size() <= 0) continue;
		}
	}
}

pair<int,int> calc_spot(int x, int y) {
	if (!(x <= 0 || y <= 0 || x > N || y > N)) return { x,y };
	if(x<=0 || x>N) x = abs(N - abs(x)); 
	if(y<=0 || y>N) y = abs(N - abs(y));
	return { x,y };
}

void fireballMove() {
	vector<Fireball> tmp[52][52];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j].size() <= 0) continue;
			for (int ii = 0;ii < board[i][j].size(); ii++) {
				Fireball fb = board[i][j][ii];
				fb.r = fb.r + (dx[fb.d] * (fb.s % N) );
				fb.c = fb.c + (dy[fb.d] * (fb.s % N) );
				pair<int, int> spot = calc_spot(fb.r,fb.c);
				fb.r = spot.X; fb.c = spot.Y;
				tmp[fb.r][fb.c].push_back(fb);
			}
		}
	}
	copyBoard(tmp);
}

void unionFireball() {
	vector<Fireball> tmp[52][52];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j].size() == 1) tmp[i][j] = board[i][j];
			if (board[i][j].size() <= 1) continue;

			Fireball fb; fb.r = i; fb.c = j; fb.s = 0; fb.m = 0;
			bool isOdd = true, isEven = true;
			for (int ii = 0; ii < board[i][j].size(); ii++) {
				fb.m += board[i][j][ii].m;
				fb.s += board[i][j][ii].s;
				fb.d = board[i][j][ii].d;
				if (fb.d % 2 == 0) isOdd = false;
				else isEven = false;
			}
			fb.s = fb.s / board[i][j].size();
			board[i][j].clear();
			if ((int)(fb.m / 5) <= 0) continue;
			fb.m /= 5;
			if (isOdd || isEven) {
				for (int dir = 0; dir < 4; dir ++) {
					fb.d = dirCo[dir];
					tmp[fb.r][fb.c].push_back(fb);
				}
			}
			else {
				for (int dir = 0; dir < 4; dir++) {
					fb.d = dirCx[dir];
					tmp[fb.r][fb.c].push_back(fb);
				}
			}
		}
	}
	copyBoard(tmp);
}

int sumFireball() {
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j].size() <= 0) continue;
			for (int ii = 0; ii < board[i][j].size(); ii++) {
				answer += board[i][j][ii].m;
			}
		}
	}
	return answer;
}

void solution() {
	while(K--){
		fireballMove();
		unionFireball();
	}

	cout << sumFireball() << '\n';
}

int main() {
	init();
	input();
	solution();
}
