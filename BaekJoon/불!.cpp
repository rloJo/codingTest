#include <iostream>
#include <queue>

/*
지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!

미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부,
그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.
지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다) 이동한다.
불은 각 지점에서 네 방향으로 확산된다.
지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
지훈이와 불은 벽이 있는 공간은 통과하지 못한다.

입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 
단, 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.
다음 입력으로 R줄동안 각각의 미로 행이 주어진다.
각각의 문자들은 다음을 뜻한다.
#: 벽
.: 지나갈 수 있는 공간
J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
F: 불이 난 공간
J는 입력에서 하나만 주어진다.

*/

using namespace std;

string maze[1002]; // 미로 
int Fdist[1002][1002]; //불의 전파 시간
int Jdist[1002][1002]; // 지훈이의 이동시간
int dx[4] = {1,0,-1,0}; 
int dy[4] = {0,1,0,-1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int R, C;
	queue <pair<int,int>> fQ;
	queue<pair<int, int>> jQ;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> maze[i];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			Jdist[i][j] = -1;
			Fdist[i][j] = -1;
			if (maze[i][j] == 'F') {
				fQ.push({ i,j });
				Fdist[i][j] = 0;
			}

			if (maze[i][j] == 'J') {
				jQ.push({ i,j });
				Jdist[i][j] = 0;
			}
			// 불과 지훈이의 위치 일 때 Fdist, Jdist 각각 0 초기화
			// 및 나머지 일때는 -1로 초기화
		}
	}

	//불 BFS
	while (!fQ.empty()) {
		pair<int, int> cur = fQ.front();
		fQ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second  + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (Fdist[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
			Fdist[nx][ny] = Fdist[cur.first][cur.second] + 1;
			fQ.push({ nx,ny });
		}
	}

	// 지훈 BFS
	while (!jQ.empty()) {
		pair<int, int> cur = jQ.front();
		jQ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) { 
				//범위를 벗어났다는 것은 현재 위치가 테두리 부분에 있다는 것을 의미
				// 즉 다음번에 탈출 
				cout << Jdist[cur.first][cur.second]+1;
				return 0;
			}
			if (Jdist[nx][ny] >= 0 || maze[nx][ny] == '#') continue; //벽이거나 이미 방문한점이면
			if (Fdist[nx][ny] != -1 && Fdist[nx][ny] <= Jdist[cur.first][cur.second] + 1) continue;
			//해당 칸에 불의 전파시간보다 지훈이의 이동시간이 같거나 더 길면 못가는 조건  추가

			Jdist[nx][ny] = Jdist[cur.first][cur.second] + 1;
			jQ.push({ nx,ny });
		}
	}

	cout << "IMPOSSIBLE";

}

/*
동시에 해결하려고 하지말고
두가지로 나눠서 해결하자
훨씬 깔끔하고 쉽게 구현이 가능하다
*/
