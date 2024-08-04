#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct Position {
	int x;
	int y;
	int emptySeat;
	int friendCnt;

};

int N;
vector<vector<int>> student(402,vector<int>(4));
int order[402];
int Class[22][22];
int satisfy = 0;
int score[5] = { 0,1,10,100,1000 };

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
	for (int i = 1; i <= N * N; i++){
		cin >> order[i];
		for (int j = 0; j < 4; j++) {
			int Friend;
			cin >> Friend;
			student[order[i]][j] = Friend;
		}
	}
}

bool OOB(int x, int y) {
	return x <= 0 || y <= 0 || x > N || y > N;
}

bool Condition(Position a ,Position b) {
	if (a.friendCnt != b.friendCnt) return a.friendCnt > b.friendCnt;
	if (a.friendCnt == b.friendCnt) {
		if (a.emptySeat != b.emptySeat) return a.emptySeat > b.emptySeat;
		if (a.emptySeat == b.emptySeat) {
			if (a.x != b.x) return a.x < b.x;
			return a.y < b.y;
		}
	}
}

void find_seat() {
	for (int i = 1; i <= N*N ; i++) {
		vector<Position> pos;
		int studentNum = order[i];
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				if (Class[x][y] != 0) continue;
				int emptySeat = 0;
				int friendSeat = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (OOB(nx, ny)) continue;
					if (Class[nx][ny] == 0) emptySeat++;
					else {
						for (int idx = 0; idx < 4; idx++) {
							if (Class[nx][ny] == student[order[i]][idx]) {
								friendSeat++;
								break;
							}
						}
					}
				}
				pos.push_back({ x,y,emptySeat,friendSeat });
			}
		}
		sort(pos.begin(), pos.end(), Condition);
		Class[pos[0].x][pos[0].y] = order[i];
	}
}

void Calc_satisfy() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int s = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (OOB(nx, ny)) continue;
				for (int f = 0; f < 4; f++) {
					if (Class[nx][ny] == student[Class[i][j]][f]) {
						s++;
						break;
					}
				}
			}
			satisfy += score[s];
		}
	}
}

void solution() {
	find_seat();
	Calc_satisfy();
	cout << satisfy << "\n";
}

int main() {
	init();
	input(); 
	solution();
}
