#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second
#define MAX  0x7f7f7f7f
using namespace std;


int N, M;
int board[52][52];
int emptys = 0; // 빈공간의 수
int vis[52][52]; // 방문시간 배열
int ans = MAX; // 최소 시간을 구해야 하므로 큰수로 초기화
queue<pair<int, int>> virus;
vector<pair<int, int>> spot; // 바이러스가 있을 수 있는 칸
int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };

bool OOB(int x, int y) { //Out of Bounds
	return x < 0 || x >= N || y < 0 || y >= N;
}

void init_vis() { //방문 배열 초기화
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			vis[i][j] = -1;
}

int bfs() {
	int times = 0;
	int num = 0;

	while (!virus.empty()) {
		pair<int,int> cur = virus.front(); virus.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny) || board[nx][ny] == 1) continue; // 벽이거나 OOB일경우
			if (vis[nx][ny] != -1) continue;  // 이미 방문한 경우 (vis 배열을 -1로 초기화)
			virus.push({nx,ny}); // nx ny 좌표 넣기
			vis[nx][ny] = vis[cur.X][cur.Y] + 1; //방문 시간 갱신
			if (board[nx][ny] != 2) { //바이러스칸이 아니면 바이러스 칸인 경우는 고려할 필요가 없음
				times = vis[nx][ny]; // 시간 갱신
				num++; // 감염방 수 증가
			}
		}
	}

	if (emptys == num) return times; //빈방의 개수와 감염된 방의 수가 같으면 시간 return
	return MAX;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) emptys++;
			if (board[i][j] == 2) spot.push_back({ i,j });
		}
	}
	vector<int> v(spot.size());

	for (int i = 0; i < spot.size(); i++) {
		if (i < M) v[i] = 0; // 바이러스 만큼 0 삽입
		else v[i] = 1; // 남은 공간은 1 삽입
	}

	do {
		init_vis();
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0) { //바이러스가 들어갈 칸
				virus.push({ spot[i].X, spot[i].Y }); // 해당 칸에 바이러스 추가
				vis[spot[i].X][spot[i].Y] = 0; // 방문 배열 바이러스칸 0설정
			}
		}
		ans = min(ans,bfs());
	} while (next_permutation(v.begin(), v.end())); // 전체 탐색

	if (ans == MAX)  cout << -1; //ans가 큰 수이면 바이러스가 전체로 퍼질수 없음
	else cout << ans;

	return 0;
}
