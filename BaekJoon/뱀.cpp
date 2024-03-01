#include <iostream>
#include <deque>
#include <queue>
/*
'Dummy' 라는 도스게임이 있다. 이 게임에는 뱀이 나와서 기어다니는데, 사과를 먹으면 뱀 길이가 늘어난다. 
뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.
게임은 NxN 정사각 보드위에서 진행되고, 몇몇 칸에는 사과가 놓여져 있다. 보드의 상하좌우 끝에 벽이 있다.
게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.
뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다.

먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라.


첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ N ≤ 100) 다음 줄에 사과의 개수 K가 주어진다. (0 ≤ K ≤ 100)
다음 K개의 줄에는 사과의 위치가 주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미한다. 
사과의 위치는 모두 다르며, 맨 위 맨 좌측 (1행 1열) 에는 사과가 없다.
다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)
다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데, 정수 X와 문자 C로 이루어져 있으며. 
게임 시작 시간으로부터 X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. 
X는 10,000 이하의 양의 정수이며, 방향 전환 정보는 X가 증가하는 순으로 주어진다.
*/

using namespace std;

#define X first
#define Y second

int N, K, L;
pair<int, int> apple; // 사과 좌표
deque<pair<int, int>>snake; // 뱀 좌표 front 머리 back 꼬리
queue<pair<int, int>> instruct; // 명령어 저장
int board[102][102]; 
int dir = 1; // 뱀의 방향 처음은 동쪽 -> 1
int dx[4]{-1,0,1,0}; // 북 0 동 1 남 2 서 3
int dy[4]{0,1,0,-1}; 
int ans = 0; // 정답 변수

bool OOB(int x, int y) { //Out Of Bound 판단
	return x < 0 || x >= N || y < 0 || y >= N;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> apple.first >> apple.second;
		board[apple.first - 1][apple.second - 1] = 1; //사과가 있으면 1 뱀의 몸이 있으면 둘다아니면 0;
	}
	cin >> L;
	board[0][0] = -1; // 처음 뱀 위치 보드 수정
	snake.push_front({ 0,0 }); // 뱀머리 꼬리 삽입
	for (int i = 0; i < L; i++) {
		int time; char d;
		cin >> time >> d;
		instruct.push({ time, d });
	}

	while (1) {

		if (!instruct.empty() && instruct.front().first == ans) {
			if (instruct.front().second == 'L') { //명령어 L이면 뱀 방향 회전
				dir -= 1;
				if (dir < 0) dir = 3;
			}
			else {  // 명령어 D이면 뱀 방향 회전
				dir = (dir + 1) % 4;
			}
			instruct.pop();
		}

		int hx = snake.front().X; //머리 X,Y 
		int hy = snake.front().Y; 
		int tx = snake.back().X; // 꼬리 X,y
		int ty = snake.back().Y;
		ans++;
		hx += dx[dir];
		hy += dy[dir];
		snake.push_front({ hx, hy }); // 머리위치 변경

		if (OOB(hx,hy) || board[hx][hy] == -1) { //벽에 부딪치거나 자신의 몸에 닿으면 초 출력하고 return
			cout << ans << "\n";
			return 0;
		}

		if (board[hx][hy] == 1) { //해당 칸이 사과이면
			board[hx][hy] = -1; // 해당 좌표 방문 표시
			// 꼬리는 그대로!
		}

		if (board[hx][hy] == 0) { //해당 칸이 아무것도 아니면 
			board[hx][hy] = -1; // 머리칸 수정
			board[tx][ty] = 0; // 꼬리에 있던 칸 0으로 변경
			snake.pop_back(); // 다음 꼬리 좌표를 위해 pop 		
		}
	
	}

	return 0;
}
