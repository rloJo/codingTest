#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int N, L, R;
int board[104][104]; // 인구수 저장
bool vis[104][104]; // 방문 배열
int ans = 0; // 정답 일수 기록

int dx[4] = {2,0,-2,0}; //남 동 북 서 순
int dy[4] = {0,2,0,-2};
int dx2[4] = { 1,0,-1,0 }; //남 동 북 서 순
int dy2[4] = { 0,1,0,-1 };

bool OOB(int x, int y) {
	return x < 0 || x >= 2 * N || y < 0 || y >= 2 * N;
}

void immigration() {
	for (int i = 0; i < 2 * N; i += 2) {
		for (int j = 0; j < 2 * N; j += 2) {
			queue<pair<int, int>> Q;
			queue<pair<int, int>>Q2;
			int cnt = 0; //나라 크기
			int people = 0; // 총 인구 수
			if (!vis[i][j]) {
				Q.push({ i,j });
				Q2.push({ i,j });
				vis[i][j] = true;
			}
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				people += board[cur.first][cur.second];
				cnt++;
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					int nx2 = cur.first + dx2[i];
					int ny2 = cur.second + dy2[i];

					if (OOB(nx, ny)|| OOB(nx2,ny2) || vis[nx][ny] == 1) continue;
					if (board[nx2][ny2] == -1) continue; // 국경이 닫힘
					Q.push({ nx,ny }); Q2.push({ nx,ny });
					vis[nx][ny] = true;
				}
			}

			while (!Q2.empty()) {
				board[Q2.front().first][Q2.front().second] = (int) people/cnt;
				Q2.pop();
			}
		}
	}
}

bool open() // 국경 열기
{
	bool flag = false; //국경이 열린 상태
	for (int i = 0; i < 2 * N; i += 2) {
		for (int j = 0; j < 2 * N; j += 2) {
			if ((i+2) <N*2 && L <= abs(board[i][j] - board[i + 2][j]) && R >= abs(board[i][j] - board[i + 2][j])) { //아랫나라 검사
				board[i + 1][j] = -2; // 국경 오픈
				flag = true;
			}
			if ((j+2) < N*2 && L <= abs(board[i][j] - board[i][j+2]) && R >= abs(board[i][j] - board[i][j+2])) { //옆나라 검사
				board[i][j+1] = -2; // 국경 오픈
				flag = true;
			}
		}
	}
	return flag;
}

void close() // 국경 닫음 및 방문 배열 초기화
{
	for (int i = 0; i < N * 2; i++) { //국경 표시 -1이면 닫힘 -2이면 열림
		if (i % 2 == 0) {
			for (int j = 1; j < N * 2; j += 2)
				board[i][j] = -1;
		}
		else {
			for (int j = 0; j < N * 2; j++)
				board[i][j] = -1;
		}
	}

	for (int i = 0; i < 2 * N; i++)
		for (int j = 0; j < 2 * N; j++)
			vis[i][j] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L >> R;

	for (int i = 0; i < N * 2; i+=2) {
		for (int j = 0; j < N * 2; j+=2) 
			cin >> board[i][j];
	}
	close();
	while (open()) {
		immigration();
		ans++;
		close();
	}
	cout << ans << "\n";
	return 0;
}
