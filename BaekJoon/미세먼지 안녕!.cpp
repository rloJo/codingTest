#include <iostream>
#include <vector>
#include <map>
#include <deque>

#define X first 
#define Y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int R, C, T;
int room[52][52];

vector<pair<int, int>> airCleaner;

inline bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= R || y >= C;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) airCleaner.push_back({ i,j });
		}
	}
}

void diffusion() {
	map<pair<int, int>, int> finedust;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] <= 0) continue;
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (OOB(nx, ny)) continue;
				if (room[nx][ny] == -1) continue;
				finedust[make_pair(nx, ny)] += room[i][j] / 5;
				cnt++;
			}
			room[i][j] -= (room[i][j] / 5) * cnt;
		}
	}

	for (auto fd : finedust) room[fd.first.X][fd.first.Y] += fd.second;
}

void cleaner() {
	deque<pair<pair<int,int>, int>> circul;  // 반시계
	pair<int, int> cur = airCleaner[0]; cur.Y+=2;

	int dir = 0;
	while (1) {
		if (dir == 0) {
			circul.push_back({ cur, room[cur.X][cur.Y - 1] });
			if (cur.Y == C - 1) {
				dir++; cur.X--; 
				continue;
			}

			cur.Y++;
		}
		else if (dir == 1) {
			circul.push_back({ cur, room[cur.X+1][cur.Y] });
			if (cur.X == 0) { 
				dir++; cur.Y--;
				continue;
			}

			cur.X--;
		}
		else if (dir == 2) {
			circul.push_back({ cur, room[cur.X][cur.Y+1] });
			if (cur.Y == 0) {
				dir++;  cur.X++;
				continue;
			}

			cur.Y--;
		}
		else {
			circul.push_back({ cur, room[cur.X-1][cur.Y] });
			if (cur == airCleaner[0]) break;
			cur.X++;
		}
	}

	deque<pair<pair<int, int>, int>> Rcircul; //시계
	pair<int, int> Rcur = airCleaner[1]; Rcur.Y += 2;
	
	dir = 0;
	while (1) {
		if (dir == 0) {
			Rcircul.push_back({ Rcur, room[Rcur.X][Rcur.Y - 1] });
			if (Rcur.Y == C - 1) { 
				dir++; Rcur.X++;
				continue;
			}
			Rcur.Y++;
		}
		else if (dir == 1) {
			Rcircul.push_back({ Rcur, room[Rcur.X - 1][Rcur.Y] });
			if (Rcur.X == R-1) { 
				dir++; Rcur.Y--;
				continue;
			}

			Rcur.X++;
		}
		else if (dir == 2) {
			Rcircul.push_back({ Rcur, room[Rcur.X][Rcur.Y + 1] });
			if (Rcur.Y == 0) {
				dir++;  Rcur.X--; 
				continue;
			}

			Rcur.Y--;
		}
		else {
			Rcircul.push_back({ Rcur, room[Rcur.X + 1][Rcur.Y] });
			if (Rcur == airCleaner[1]) break;
			Rcur.X--;
		}
	}

	while (!circul.empty()) {
		auto c = circul.front(); circul.pop_front();
		room[c.first.X][c.first.Y] = c.second;
	}

	while (!Rcircul.empty()) {
		auto c = Rcircul.front(); Rcircul.pop_front();
		room[c.first.X][c.first.Y] = c.second;
	}

	room[airCleaner[1].X][airCleaner[1].Y] = -1;
	room[airCleaner[0].X][airCleaner[0].Y] = -1;
	room[airCleaner[1].X][airCleaner[1].Y + 1] = 0;
	room[airCleaner[0].X][airCleaner[0].Y + 1] = 0;
}

int calcFD() {
	int answer = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] < 0) continue;
			answer += room[i][j];
		}
	}
	return answer;
}

void solution() {
	while (T--) {
		diffusion();
		cleaner();
	}

	cout << calcFD() << "\n";
}

int main() {
	init();
	input(); 
	solution();
}
