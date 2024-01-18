#include <iostream>
#include <queue>

/*
체스판 위에 한 나이트가 놓여져 있다.
나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다.
나이트가 이동하려고 하는 칸이 주어진다. 
나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?


입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.
각 테스트 케이스는 세 줄로 이루어져 있다. 
첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 
체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다.
둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.
*/

using namespace std;

int board[302][302];
int dist[302][302];

int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
// 나이트가 이동하는 방향 8가지

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, l;
	cin >> T;
	while (T--) {
		queue <pair<int, int>> Q;
		int x1, y1, x2, y2;
		int ans = 0;
		cin >> l;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				dist[i][j] = -1;
			}
		}
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		dist[x1][y1] = 0;
		Q.push({ x1,y1 });
		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
				if (dist[nx][ny] >= 0) continue;
				if (nx == x2 && ny == y2) { 
					//다음 이동하는 곳이 원하는 위치면 dist값 1 증가후 해당 칸에 저장 후 탈출
					dist[nx][ny] = dist[cur.first][cur.second] + 1;
					break;
				}
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				Q.push({ nx,ny });
			}
		}
		cout << dist[x2][y2] << "\n";
	}
	return 0;
}
