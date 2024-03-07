#include <iostream>
#include <queue>

/*
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 
다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.

연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다.
연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다.

일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다.
새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.

2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 
아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.
2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.

2 1 0 0 1 1 0
1 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 1 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

바이러스가 퍼진 뒤의 모습은 아래와 같아진다.

2 1 0 0 1 1 2
1 0 1 0 1 2 2
0 1 1 0 1 2 2
0 1 0 0 0 1 2
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다.
위의 지도에서 안전 영역의 크기는 27이다.
연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.


첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
둘째 줄부터 N개의 줄에 지도의 모양이 주어진다.
0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다.
2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
빈 칸의 개수는 3개 이상이다.

*/
using namespace std;

#define X first
#define Y second

int N, M;
queue<pair<int, int>> v;
int board[10][10];
int ans = -1;
int dx[4] = { 1, 0,-1, 0}; //BFS 를 위한 방향 
int dy[4] = { 0, 1, 0,-1}; //바이러스가 전이 되고나서의 상태구하기 위한

bool OOB(int x, int y){ //Out Of Bounds
	return x < 0 || x >= N || y < 0 || y >= M;
}

int check() { //안전 지역 크기 체크
	int safe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0)
				safe++;
		}
	}
	return safe;
}

void bfs(queue<pair<int, int>>v) { //board bfs 너비 탐색
	while (!v.empty()) {
		pair<int, int> cur = v.front();
		v.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (OOB(nx, ny)|| board[nx][ny]!=0) continue;
			v.push({ nx,ny });
			board[nx][ny] = 2;
		}
	}
}

void dfs(int k, int idx, queue<pair<int,int>>virus) { //2차원 배열 3가지 조합 dfs로 모두 탐색
	
	int tmp[10][10]; // 배열을 원상복구 하기 위한 배열

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmp[i][j] = board[i][j]; 

	if (k == 3) { // 벽 위치 3개를 다 뽑았으면
		bfs(virus);  // bfs 후 안전 지대 개수 파악
		ans = max(ans,check());
		for (int i = 0; i < N; i++) // 다시 배열 초기화
			for (int j = 0; j < M; j++)
				board[i][j] = tmp[i][j];
		
		return;
	}

	for (int i = idx; i < N * M; i++) { //조합 모두 찾기 총 N*M개의 배열중에 3개를 뽑는 것
		int nx = i / M; // 뽑은 칸의 x 좌표 
		int ny = i % M; // 뽑은 칸의 y 좌표
		if (OOB(nx, ny) || board[nx][ny] !=0) continue; 
		else {
			board[nx][ny] = 1;
			dfs(k + 1, i, virus);
			board[nx][ny] = 0;
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<pair<int, int>> virus;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				virus.push({ i,j });
		}
	}

	dfs(0,0,virus);

	cout << ans << "\n";
	return 0;
}
