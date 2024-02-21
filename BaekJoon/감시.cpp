#include <iostream>
#include <vector>
/*
스타트링크의 사무실은 1×1크기의 정사각형으로 나누어져 있는 N×M 크기의 직사각형으로 나타낼 수 있다. 
사무실에는 총 K개의 CCTV가 설치되어져 있는데, CCTV는 5가지 종류가 있다. 
각 CCTV가 감시할 수 있는 방법은 다음과 같다.

1번	2번	3번	4번	5번
1번 CCTV는 한 쪽 방향만 감시할 수 있다. 
2번과 3번은 두 방향을 감시할 수 있는데, 2번은 감시하는 방향이 서로 반대방향이어야 하고,
3번은 직각 방향이어야 한다. 
4번은 세 방향, 5번은 네 방향을 감시할 수 있다.
CCTV는 감시할 수 있는 방향에 있는 칸 전체를 감시할 수 있다. 
사무실에는 벽이 있는데, CCTV는 벽을 통과할 수 없다. 
CCTV가 감시할 수 없는 영역은 사각지대라고 한다.
CCTV는 회전시킬 수 있는데, 회전은 항상 90도 방향으로 해야 하며,
감시하려고 하는 방향이 가로 또는 세로 방향이어야 한다.

첫째 줄에 사무실의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 8)

둘째 줄부터 N개의 줄에는 사무실 각 칸의 정보가 주어진다. 
0은 빈 칸, 6은 벽, 1~5는 CCTV를 나타내고, 문제에서 설명한 CCTV의 종류이다.
CCTV의 최대 개수는 8개를 넘지 않는다.
*/

using namespace std;

// 남, 동, 북, 서 순서
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int N, M;

int board[10][10]; // 최초 사무실 상태를 입력 받는 배열
int cnt[10][10]; // 사무실의 사각지대의 개수를 세는 변수

vector<pair<int, int>> S; // cctv의 좌표를 저장하는 벡터
int ans = 10000; //사각지대의 개수를 저장하는 변수


inline bool OOB(int a, int b) { //좌표를 지정할 떄 범위 판단 함수
	return a < 0 || a >= N || b < 0 || b >= M;
}

void check(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (OOB(x, y) || board[x][y] == 6) return; //범위를 벗어났거나 벽에 마주하면 return;
		if (board[x][y] != 0) continue; //해당칸에 CCTV가 설치 되어 있거나 이미 CCTV로 확인중이면 넘어감
		board[x][y] = 10; // cctv 가 확인하는 구역은 10으로 설정
	}
}

void dfs(int k) {
	if (k == S.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				if (!board[i][j]) cnt++;
		}
		ans = min(ans, cnt);
		return;
	}

	int nx = S[k].first;
	int ny = S[k].second;
	int tmp[10][10];

	for (int dir = 0; dir < 4; dir++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp[i][j] = board[i][j];
			}
		}

		if (board[nx][ny] == 1) { //dir이 1증가하면 90도 회전
			check(nx, ny, dir);
		}
		else if (board[nx][ny] == 2) { //남북, 동서 검사
			check(nx, ny, dir); 
			check(nx, ny, dir + 2); 
		} 
		else if (board[nx][ny] == 3) { //남동, 동북, 북서, 서남 순으로 검사
			check(nx, ny, dir);
			check(nx, ny, dir + 1);
		}

		else if (board[nx][ny] == 4) { //남동북, 동북서 ..... 순으로 검사
			check(nx, ny, dir);
			check(nx, ny, dir + 1);
			check(nx, ny, dir + 2);
		}

		else if (board[nx][ny] == 5) { //동서남북 다 검사
			check(nx, ny, dir);
			check(nx, ny, dir + 1);
			check(nx, ny, dir + 2);
			check(nx, ny, dir + 3);
		}

		dfs(k + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				board[i][j] = tmp[i][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] <= 5 && board[i][j] >= 1)// 1 ~ 5 사이이면 카메라 -> 좌표 기억
				S.push_back({ i,j });
		}
	}

	dfs(0);
	cout << ans;

	return 0;
}
