#include <iostream>
#include <queue>

/*
어떤 큰 도화지에 그림이 그려져 있을 때, 
그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라.
단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자.
가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다.
그림의 넓이란 그림에 포함된 1의 개수이다.

첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다.
두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다. 
(단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)

*/

using namespace std;

int board[502][502];
bool vis[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue <pair<int, int>> Q;
	int n, m;
	int max = 0, count = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			vis[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 || vis[i][j] == 1) continue; //board의 칸이 0이거나 방문한 점이면 loop 넘김
			count++;		//if문을 벗어나면 무조건 그림인것 따라서 그림 수 중가
			vis[i][j] = 1;  //방문점 남김
			Q.push({ i,j });
			int area = 0;   //몇칸으로 되어있는지 확인하는 변수
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop(); //pop을 하면 그림칸 증가 
				area++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			} 
			max = max > area ? max : area;
		}
	}

	cout << count << "\n" << max;

}
