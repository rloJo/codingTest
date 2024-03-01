#include <iostream>

/*
로봇 청소기와 방의 상태가 주어졌을 때, 청소하는 영역의 개수를 구하는 프로그램을 작성하시오.

로봇 청소기가 있는 방은 
N  M 크기의 직사각형으로 나타낼 수 있으며, 
1 X 1 크기의 정사각형 칸으로 나누어져 있다. 각각의 칸은 벽 또는 빈 칸이다. 
청소기는 바라보는 방향이 있으며, 이 방향은 동, 서, 남, 북 중 하나이다. 방의 각 칸은 좌표 
(r, c)로 나타낼 수 있고, 가장 북쪽 줄의 가장 서쪽 칸의 좌표가 (0, 0), 가장 남쪽 줄의 가장 동쪽 칸의 좌표가 (N-1, M-1)$이다.
즉, 좌표  (r, c)는 북쪽에서 (r+1)번째에 있는 줄의 서쪽에서 (c+1)번째 칸을 가리킨다.
처음에 빈 칸은 전부 청소되지 않은 상태이다.

로봇 청소기는 다음과 같이 작동한다.

현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다. 
현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
	바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
	바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
	반시계 방향으로 90도 회전한다.
	바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
	1번으로 돌아간다.
입력
첫째 줄에 방의 크기 
N과 M이 입력된다. (3 <= N, M <= 50)  
둘째 줄에 처음에 로봇 청소기가 있는 칸의 좌표 (r, c)와 처음에 로봇 청소기가 바라보는 방향 d가 입력된다. 
d가 
0인 경우 북쪽, 
1인 경우 동쪽, 
2인 경우 남쪽, 
3인 경우 서쪽을 바라보고 있는 것이다.

셋째 줄부터 
N개의 줄에 각 장소의 상태를 나타내는 N X M개의 값이 한 줄에 M개씩 입력된다. 
i번째 줄의 j번째 값은 칸 (i, j)의 상태를 나타내며, 이 값이 0인 경우(i, j)가 청소되지 않은 빈 칸이고, 1인 경우 (i, j)에 벽이 있는 것이다.
방의 가장 북쪽, 가장 남쪽, 가장 서쪽, 가장 동쪽 줄 중 하나 이상에 위치한 모든 칸에는 벽이 있다. 
로봇 청소기가 있는 칸은 항상 빈 칸이다.
*/

#define X first
#define Y second

using namespace std;

int N, M;
pair<int, int> robot; //로봇의 좌표
int dir; //로봇의 방향  0 북 1 동 2 남 3  서
int room[52][52]; // 방 구조
int clear[52][52]; // 치웠는지 여부
int ans = 0; // 정답 변순
int dx[4] = {-1,0,1,0}; //북동남서
int dy[4] = {0,1,0,-1};

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}

void clean() {
	pair<int, int> cur;
	cur = robot;
	while (1) {
		if (clear[cur.X][cur.Y] == 0) //현재 좌표가 청소가 안되어있으면 
		{
			clear[cur.X][cur.Y] = 1; //청소 하고 정답 1증가
			ans++;
		}
		int nx, ny;
		bool flag = false;
		for (int i = 0; i < 4; i++) { //주변 방 청소상태 확인
			nx = cur.first + dx[i];
			ny = cur.second + dy[i];
			if (OOB(nx, ny) || room[nx][ny] == 1) continue;
			if (clear[nx][ny] == 1) continue;
			flag = true;
			break;
		}

		if (flag) { //주변에 청소할 방이 있으면 반시계방향 회전
			while(1){ //청소할 방이 나올때 까지 회전
				dir -= 1;
				if (dir == -1)
					dir = 3;  
				nx = cur.first + dx[dir]; //방 정보 확인
				ny = cur.second + dy[dir];
				if (!OOB(nx, ny) && clear[nx][ny] == 0 && room[nx][ny] != 1) // 청소해야할 방이면
				{
					cur = { nx,ny }; // 현재 위치 변경
					break;
				}
			} 
		}
		else { //주변에 청소할 방이 없으면
			nx = cur.X + dx[(dir+2)%4]; // 현재 방향 반대로 후진
			ny = cur.Y + dy[(dir+2)%4];
			if (room[nx][ny] == 1) //후진을 못하면
				break;
			else { //후진 완료
				cur.X = nx;
				cur.Y = ny;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	cin >> robot.X >> robot.Y >> dir;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> room[i][j];

	clean();
	cout << ans << "\n";
	return 0;
}
