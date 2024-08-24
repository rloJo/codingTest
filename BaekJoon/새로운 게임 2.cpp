#include <iostream>
#include <vector>

using namespace std;

// 우 좌 상 하
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

struct Piece {
	int x;
	int y;
	int floor;
	int dir;
};

int N,K;
int board[13][13];
vector<int> state[13][13];
Piece pieces[13];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int x,y,dir;
		cin >> x >> y >> dir;
		pieces[i] = { x-1,y-1,0,dir };
		state[x-1][y-1].push_back(i);
	}
}

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= N;
}

bool move(int cx, int cy, int nx,int ny, int f, int col) {
	int curFloor = (int)state[cx][cy].size();
	int topFloor = (int)state[nx][ny].size();
	int floor = 0;
	if (col == 0) {
		for (int i = f; i < curFloor; i++) {
			state[nx][ny].push_back(state[cx][cy][i]);
			pieces[state[cx][cy][i]].x = nx;
			pieces[state[cx][cy][i]].y = ny;
			pieces[state[cx][cy][i]].floor = topFloor + floor++;
			if (pieces[state[cx][cy][i]].floor >= 3) return false;
		}
		state[cx][cy].erase(state[cx][cy].begin()+f, state[cx][cy].end());

		return true;
	}

	if (col == 1) {
		for (int i = curFloor-1; i >= f; i--) {
			state[nx][ny].push_back(state[cx][cy][i]);
			pieces[state[cx][cy][i]].x = nx;
			pieces[state[cx][cy][i]].y = ny;
			pieces[state[cx][cy][i]].floor = topFloor + floor++;
			if (pieces[state[cx][cy][i]].floor >= 3) return false;
		}
		state[cx][cy].erase(state[cx][cy].begin() + f, state[cx][cy].end());
		return true;
	}
}

bool movePiece(int num) {
	int f = pieces[num].floor;
	int cx = pieces[num].x;
	int cy = pieces[num].y;
	int nx = cx + dx[pieces[num].dir];
	int ny = cy + dy[pieces[num].dir];

	// 파란색인경우
	if (OOB(nx, ny) || board[nx][ny] == 2) {
		if (pieces[num].dir % 2 == 1) pieces[num].dir++;
		else pieces[num].dir--;
		nx = cx + dx[pieces[num].dir];
		ny = cy + dy[pieces[num].dir];
		if (OOB(nx, ny) || board[nx][ny] == 2) return true;
		if(board[nx][ny] == 0) return move(cx, cy, nx, ny, f, 0);
		if (board[nx][ny] == 1) return move(cx, cy, nx, ny,f, 1);
	}

	//흰색
	if (board[nx][ny] == 0) {
		return move(cx, cy, nx, ny, f, 0);
	}

	//빨간색
	if (board[nx][ny] == 1) {
		return move(cx, cy, nx, ny,f,1);
	}

	return true;
}

void solution() {
	int turn = 0;
	bool gameover = false;
	while (turn <= 1000 && !gameover) {
		turn++;
		for (int i = 0; i < K; i++) {
			if (!movePiece(i)) {
				gameover = true;
				break;
			}
		}
	}
	if (turn > 1000) cout << -1;
	else cout << turn;
}

int main() {
	init();
	input();
	solution();
}
