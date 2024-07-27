#include <iostream>
#include <queue>
#include <vector>
#define X first 
#define Y second

using namespace std;

char board[1502][1502] = { 0 }; 
bool vis[1502][1502] = { 0 }; 

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int R, C;
pair<int, int> swan;
queue<pair<int, int>> WQ, WNQ, SQ, SNQ;

bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= R || y >= C;
}

bool SBFS() {
	while (!SQ.empty()) {
		pair<int, int> cur = SQ.front(); SQ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (vis[nx][ny]) continue;
			if (board[nx][ny] == '.') {
				vis[nx][ny] = true;
				SQ.push({ nx,ny });
			}
			if (board[nx][ny] == 'L') {
				return true;
			}
			if (board[nx][ny] == 'X') {
				vis[nx][ny] = true;
				SNQ.push({ nx,ny });
			}
		}
	}
	return false;
}

void WBFS() {
	while (!WQ.empty()) {
		pair<int, int> cur = WQ.front(); WQ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)) continue;
			if (board[nx][ny] == 'X') {
				board[nx][ny] = '.';
				WNQ.push({ nx,ny });
			}
		}
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer = 0;
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'L') {
				swan = { i,j };
			}
			if (board[i][j] != 'X') WQ.push({ i,j });
		}
	}
	
	vis[swan.X][swan.Y] = true;
	SQ.push(swan);

	while (1) {
		if (SBFS()) {
			break;
		}

		WBFS();
		WQ = WNQ;
		SQ = SNQ;

		while (!SNQ.empty()) SNQ.pop();
		while (!WNQ.empty()) WNQ.pop();
		answer++;
	}

	cout << answer;

	return 0;
}
