#include <iostream>
#include <vector>

using namespace std;

struct Robot {
	int x;
	int y;
	int dir;
};
//NESW
int dx[4] ={-1,0,1,0};
int dy[4] ={0,1,0,-1};

int A, B;
int N, M;
pair<bool,int> ground[102][102];
vector<Robot> robots(102);

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> A >> B;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int x, y, idx; char dir;
		cin >> y >> x >> dir;
		if (dir == 'N') idx = 0;
		if (dir == 'E') idx = 1;
		if (dir == 'S') idx = 2;
		if (dir == 'W') idx = 3;
		robots[i] = { B-x,y-1, idx };
		ground[B-x][y-1].first = true;
		ground[B-x][y-1].second = i;
	}
}

bool OOB(int x, int y){
	return x < 0 || y < 0 || x >= B || y >= A;
}

pair<bool,int> robot(int robotnum, char ins) {
	if (ins == 'L') robots[robotnum].dir = (robots[robotnum].dir + 3) % 4;
	if (ins == 'R') robots[robotnum].dir = (robots[robotnum].dir + 1) % 4;
	if (ins == 'F') {
		ground[robots[robotnum].x][robots[robotnum].y] = { false, 0 };
		robots[robotnum].x += dx[robots[robotnum].dir];
		robots[robotnum].y += dy[robots[robotnum].dir];
		if (OOB(robots[robotnum].x, robots[robotnum].y)) return { false,-1 };
		if (ground[robots[robotnum].x][robots[robotnum].y].first) return { false, ground[robots[robotnum].x][robots[robotnum].y].second };
		ground[robots[robotnum].x][robots[robotnum].y] = { true, robotnum };
	}
	return { true,0 };
}

void solution() {
	pair<bool, int> result;
	for (int i = 0; i < M; i++) {
		int num, cnt;
		char instruction;
		cin >> num >> instruction >> cnt;
		while (cnt--) {
			result = robot(num, instruction);
			if (!result.first) {
				if (result.second == -1) cout << "Robot " << num << " crashes into the wall";
				else cout << "Robot " << num << " crashes into robot " << result.second;
				return;
			}
		}
	}
	cout << "OK";
}

int main() {
	init();
	input();
	solution();
}
