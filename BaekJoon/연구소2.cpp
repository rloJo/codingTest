#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int N, M;
int board[52][52];
int vis[52][52];
int ans = 1000; // 최소 시간을 구해야 하므로 큰수로 초기화

int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };

queue<pair<int, int>> virus;

bool OOB(int x, int y) { //Out of Bounds
	return x < 0 || x >= N  || y < 0 || y >= N;
}

void init_vis(){ //방문 배열 초기화
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			vis[i][j] = 0;
}

void check() {
	bool flag = false;
	int mn = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1) continue; // 벽인 경우 vis배열이 0이므로 통과
			if (vis[i][j] == 0) { // vis배열에 0이 있는 경우
				flag = true; // 바이러스가 다 못퍼짐
				break;
			}
			else {
				mn = max(vis[i][j] -1, mn); // 걸리는 시간의 최대값
			}
		}
	}

	if (!flag) { // 다 채울수 있으면
		ans = min(ans, mn); //최소값 갱신;
	}
}

void bfs() {
	while (!virus.empty()) {
		pair<int, int> cur = virus.front(); 
		virus.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || board[nx][ny] == 1) continue; // 벽이거나 OOB일경우
			if (vis[nx][ny] != 0) continue; // 이미 방문한 경우
			vis[nx][ny] = vis[cur.X][cur.Y] + 1; // 이전보다 1초 더 걸림 방문 표시
			virus.push({ nx,ny }); // 큐에 좌표 삽입
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> spot;
	int cnt = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				spot.push_back({ i,j });
				cnt++;
			}
		}
	}

	vector<int> v(cnt);
	for (int i = 0; i < cnt; i++) {
		if (i < M) v[i] = 0; // 바이러스 만큼 0 삽입
		else v[i] = 1; // 남은 공간은 1 삽입
	}

	do {
		int idx = 0;
		for(int i=0;i<v.size();i++){
			if (v[i] == 0) { //바이러스가 들어갈 칸
				virus.push(spot[i]); // 해당 칸에 바이러스 추가
				vis[spot[i].X][spot[i].Y] = 1; // 방문 배열 바이러스칸 1설정
			}
		}
		bfs();
		check();
		init_vis();
	} while (next_permutation(v.begin(), v.end())); // 전체 탐색

	if (ans == 1000) { //ans가 1000이면 바이러스가 전체로 퍼질수 없음
		cout << -1;
	}
	else
	 	cout << ans;

	return 0;
}
