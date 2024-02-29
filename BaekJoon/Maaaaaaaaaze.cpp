#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

/*
평화롭게 문제를 경작하며 생활하는 BOJ 마을 사람들은 더 이상 2차원 미로에 흥미를 느끼지 않는다.
2차원 미로는 너무나 쉽게 탈출이 가능하기 때문이다.
미로를 이 세상 그 누구보다 사랑하는 준현이는 이런 상황을 매우 안타깝게 여겨
아주 큰 상금을 걸고 BOJ 마을 사람들의 관심을 확 끌 수 있는 3차원 미로 탈출 대회를 개최하기로 했다.

대회의 규칙은 아래와 같다.

5×5 크기의 판이 5개 주어진다. 이중 일부 칸은 참가자가 들어갈 수 있고 일부 칸은 참가자가 들어갈 수 없다.
그림에서 하얀 칸은 참가자가 들어갈 수 있는 칸을, 검은 칸은 참가자가 들어갈 수 없는 칸을 의미한다.

참가자는 주어진 판들을 시계 방향, 혹은 반시계 방향으로 자유롭게 회전할 수 있다.
그러나 판을 뒤집을 수는 없다.

회전을 완료한 후 참가자는 판 5개를 쌓는다. 판을 쌓는 순서는 참가자가 자유롭게 정할 수 있다.
이렇게 판 5개를 쌓아 만들어진 5×5×5 크기의 큐브가 바로 참가자를 위한 미로이다.
이 때 큐브의 입구는 정육면체에서 참가자가 임의로 선택한 꼭짓점에 위치한 칸이고 출구는 입구와 면을 공유하지 않는 꼭짓점에 위치한 칸이다.

참가자는 현재 위치한 칸에서 면으로 인접한 칸이 참가자가 들어갈 수 있는 칸인 경우 그 칸으로 이동할 수 있다.

참가자 중에서 본인이 설계한 미로를 가장 적은 이동 횟수로 탈출한 사람이 우승한다. 만약 미로의 입구 혹은 출구가 막혀있거나,
입구에서 출구에 도달할 수 있는 방법이 존재하지 않을 경우에는 탈출이 불가능한 것으로 간주한다.

이 대회에서 우승하기 위해서는 미로를 잘 빠져나올 수 있기 위한 담력 증진과 체력 훈련,
그리고 적절한 운이 제일 중요하지만,
가장 적은 이동 횟수로 출구에 도달할 수 있게끔 미로를 만드는 능력 또한 없어서는 안 된다.
주어진 판에서 가장 적은 이동 횟수로 출구에 도달할 수 있게끔 미로를 만들었을 때 몇 번 이동을 해야하는지 구해보자.

입력

첫째 줄부터 25줄에 걸쳐 판이 주어진다.
각 판은 5줄에 걸쳐 주어지며 각 줄에는 5개의 숫자가 빈칸을 사이에 두고 주어진다.
0은 참가자가 들어갈 수 없는 칸, 1은 참가자가 들어갈 수 있는 칸을 의미한다.
*/

#define X first
#define Y second

using namespace std;

int maze2[6][6][6]; // 순서를 바꿔 저장할 maze
int maze1[6][6][6]; // 입력 받을 maze
int vis[6][6][6]; // 방문 배열
int dx[6] {0, -1,  0,  0, 1, 0}; // 맨 아래칸 기준 오른쪽 아래쪽 아래칸, 왼쪽, 위쪽, 윗칸 검사 
int dy[6] {1,  0,  0, -1, 0, 0};
int dz[6] {0,  0,  -1, 0, 0, 1}; 
pair<int, int> start[4] = { {0,0},{0,4},{4,0},{4,4} }; // 시작할 수 있는 꼭지 점
int ans = 1000; // 정답 변수

bool OOB(int x, int y, int z) { //Out Of Bounds 범위 확인
	return x < 0 || x >= 5 || y < 0 || y >= 5 || z < 0 || z >= 5;
}

void find_min() {  
	queue<tuple<int,int,int>> Q;
	bool flag = false; // 방문 배열 초기화 횟수를 줄이기 위해 flag 사용

	for (int i = 0; i < 4; i++) { // 시작점은 4개가 될 수 있음 각 시작점 검사
		if (flag) { //flag 가 true이면 이전 시작점에서 vis 배열의 변화가 일어남 따라서 초기화
			for (int ii = 0; ii < 5; ii++)
			{
				for (int jj = 0; jj < 5; jj++)
				{
					for (int kk = 0; kk < 5; kk++) {
						vis[ii][jj][kk] = 0;
					}
				}
			}
		}

		//시작 점이 0이거나 끝지점이 0이면 다음 시작점 검사
		if (maze2[4][start[i].X][start[i].Y] == 0 || maze2[0][4-start[i].X][4-start[i].Y] == 0)
			continue;
		else { //둘다 갈 수 있는 경우 Q에 넣고 bfs;
			Q.push({ 4,start[i].X ,start[i].Y });
			vis[4][start[i].X][start[i].Y] = 1;
			flag = true;
		}
		//bfs
		while (!Q.empty()) {
			auto cur = Q.front(); Q.pop();
			int curX, curY, curZ;
			tie(curZ, curX, curY) = cur;
			for (int dir = 0; dir < 6; dir++) {
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				int nz = curZ + dz[dir];
				if (OOB(nx, ny, nz) || maze2[nz][nx][ny] == 0) continue;
				if (vis[nz][nx][ny] >= 1) continue;
				if ((nx + start[i].X == 4) && (ny + start[i].Y == 4) && nz == 0) {
					ans = min(ans,vis[curZ][curX][curY]);
					while (!Q.empty()) Q.pop();
					break;
				}
				Q.push({ nz,nx,ny });
				vis[nz][nx][ny] = vis[curZ][curX][curY] + 1;
			}
		}
	}
}

// 2차원 배열을 90도 회전하는 함수
void spin(int idx) {
	int tmp[6][6];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmp[i][j] = maze2[idx][i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			maze2[idx][i][j] = tmp[5 - 1 - j][i]; 
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> maze1[i][j][k];
			}
		}
	}
	vector<int> v {0, 1, 2, 3, 4}; // 쌓는 순서 정하는 벡터 
	do {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					maze2[i][j][k] = maze1[v[i]][j][k];
				}
			}
		}

		//각 층을 90도 씩 돌리면서 전체 검사
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int ii = 0; ii < 4; ii++) {
					for (int jj = 0; jj < 4; jj++) {
						for (int k = 0; k < 4; k++) {
							find_min();
							spin(4);
						}
						spin(3);
					}
					spin(2);
				}
				spin(1);
			}
			spin(0);
		}
	} while (next_permutation(v.begin(), v.end())); //순서를 바꿔가며 탐색

	if (ans == 1000) ans = -1; //ans가 1000일 경우 어떤 경우도 탈출 불가능한 경우
	cout << ans << "\n";

	return 0;
}
