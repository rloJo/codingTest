#include <iostream>
#include <queue>

/*
적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다.
따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.
크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다.
그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 
또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. 
(색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)
예를 들어, 그림이 아래와 같은 경우에

RRRBB
GGBBB
BBBRR
BBRRR
RRRRR

적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다.
(빨강 2, 파랑 1, 초록 1) 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)
그림이 입력으로 주어졌을 때,
적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)
둘째 줄부터 N개 줄에는 그림이 주어진다.

*/

using namespace std;

string board[102];

bool vis[102][102];
bool nvis[102][102];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int ans=0, nans=0;
	queue<pair<int, int>> Q, nQ;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> board[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (nvis[i][j] == 1) continue;
			nQ.push({ i,j });
			nans++;
			while (!nQ.empty()) // 적록 색약이 아닌 사람 BFS;
			{
				auto cur = nQ.front();
				nQ.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (nvis[nx][ny] == 1) continue;
					if (board[nx][ny] != board[cur.first][cur.second]) continue;
					nvis[nx][ny] = 1;
					nQ.push({ nx,ny });
				}
			}

			if (vis[i][j] == 1) continue; 
			Q.push({ i,j });
			ans++;
			while (!Q.empty()) // 적록 색약인 사람 BFS;
			{
				auto cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					char check = board[cur.first][cur.second];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (vis[nx][ny] == 1) continue;
					if (check == 'B' && board[nx][ny] != 'B') continue;
					if (check == 'R' && board[nx][ny] == 'B') continue;
					if (check == 'G' && board[nx][ny] == 'B') continue;
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
		}
	}

	cout << nans << " " << ans;

}

// 적록색약이 아닌 사람은 구역을 3 개로 나눔 R G B
// 적록색약인 사람은 구역을 2 개로 나눔 (R,G) B
// 함수로 분리해 작성하는 것이 보기에 좋을 수 있다
