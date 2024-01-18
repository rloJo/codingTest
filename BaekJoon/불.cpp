#include <iostream>
#include <queue>

/*
상근이는 빈 공간과 벽으로 이루어진 건물에 갇혀있다. 
건물의 일부에는 불이 났고, 상근이는 출구를 향해 뛰고 있다.
매 초마다, 불은 동서남북 방향으로 인접한 빈 공간으로 퍼져나간다. 
벽에는 불이 붙지 않는다. 상근이는 동서남북 인접한 칸으로 이동할 수 있으며, 1초가 걸린다. 
상근이는 벽을 통과할 수 없고, 불이 옮겨진 칸 또는 이제 불이 붙으려는 칸으로 이동할 수 없다.
상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.
빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 수 있는지 구하는 프로그램을 작성하시오.

첫째 줄에 테스트 케이스의 개수가 주어진다.
테스트 케이스는 최대 100개이다.
각 테스트 케이스의 첫째 줄에는 빌딩 지도의 너비와 높이 w와 h가 주어진다. (1 ≤ w,h ≤ 1000)
다음 h개 줄에는 w개의 문자, 빌딩의 지도가 주어진다.

'.': 빈 공간
'#': 벽
'@': 상근이의 시작 위치
'*': 불
각 지도에 @의 개수는 하나이다.

*/

using namespace std;

string board[1002];
int Fdist[1002][1002];
int Sdist[1002][1002];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
// 불및 상근이의 이동 방향

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int w, h;
		int ans = 0;
		bool flag = false;
		cin >> w >> h;
		queue <pair<int, int>> fQ;
		queue <pair<int, int>> sQ;
		for (int i = 0; i < h; i++) {
			cin >> board[i];
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '*') {
					Fdist[i][j] = 0;
					fQ.push({ i,j });
				}
				else if (board[i][j] == '@') {
					Sdist[i][j] = 0;
					Fdist[i][j] = -1;
					sQ.push({ i,j });
				}
				else if (board[i][j] == '.')
				{
					Fdist[i][j] = -1;
					Sdist[i][j] = -1;
				}
				else {
					Fdist[i][j] = 0;
					Sdist[i][j] = 0;
				}
			}
		}

		// 불 dfs
		while (!fQ.empty()) {
			auto cur = fQ.front();
			fQ.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny] == '#') continue;
				if (Fdist[nx][ny] >= 0) continue;
				Fdist[nx][ny] = Fdist[cur.first][cur.second] + 1;
				fQ.push({ nx,ny });
			}
		}

		// 상근이 dfs
		while (!sQ.empty()) {
			auto cur = sQ.front();
			sQ.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				{
					ans = Sdist[cur.first][cur.second] + 1;
					flag = true;
					break; // for문을 나가는 break;
				}
				if (board[nx][ny] == '#' || Sdist[nx][ny] >= 0) continue;
				if (Fdist[nx][ny]!=-1 && Sdist[cur.first][cur.second] + 1 >= Fdist[nx][ny]) continue;
				Sdist[nx][ny] = Sdist[cur.first][cur.second] + 1;
				sQ.push({ nx,ny }); 
			}
			if (flag) // 이거 없어서 시간을 너무 씀 (flag 가 true 면 while 문도 나가야함)
				break;
		}

		if (flag) {
			cout << ans << "\n";
		}
		else {
			cout << "IMPOSSIBLE" << "\n";
		}
	}

	return 0;
}
