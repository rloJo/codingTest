#include <iostream>
#include <vector>
#define X first
#define Y second

using namespace std;

// 8방향
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

// 물고기 구조체
struct Fish {
	int num; // 물고기 번호
	int x = 0; // 물고기 X 좌표
	int y = 0; // 물고기 Y 좌표
	int dir; // 물고기 방향
};

//상어 구조체 
struct Shark {
	int x = 0; // 상어 X 좌표
	int y = 0; // 상어 Y 좌표
	int dir; // 상어 방향
};

int board[4][4]; // 물고기 판
Fish fishes[17]; // 번호에 따른 물고기 정보 저장
bool isFishLive[17]; // 해당 번호 물고기 죽었는지 판단
Shark shark; // 상어 정보
int answer = 0; 

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	Fish fish;
	for (int i = 1; i <= 16; i++) isFishLive[i] = true; // 1~16 물고기 살림
	for (int i = 0; i < 4; i++) { // 물고기 정보 입력
		for(int j = 0; j < 4; j++) {
			cin >> fish.num >> fish.dir;   
			fish.x = i; fish.y = j; fish.dir--;
			board[i][j] = fish.num; // 물고기 판에 물고기 번호 기록
			fishes[fish.num] = fish; // 번호에 따른 물고기 정보 입력
		}
	}

	shark.x = 0;     // 상어는 0,0부터 시작
	shark.y = 0;	 
	shark.dir = fishes[board[0][0]].dir; // 물고기판의 0,0번쨰 물고기의 방향을 갖는다.
	answer += board[0][0]; // answer값에 0,0에 있는 물고기 번호 더해줌
	isFishLive[board[0][0]] = false; // 해당 물고기 죽음
	board[0][0] = 0; // 먹은 물고기 칸에 0 저장
}

void Copy(int A[][4], int B[][4], Fish C[], Fish D[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			A[i][j] = B[i][j];
	}

	for (int i = 1; i <= 16; i++) C[i] = D[i];
}



// 범위를 벗어났는지 확인
bool OOB(int x, int y) {
	return x < 0 || y < 0 || x >= 4 || y >= 4;
}

// 물고기가 이동할 수 있는지 확인 => 이동할 수 없으면 true 있으면 false
bool CantMove(int x, int y) {
	if (x == shark.x && y == shark.y) return true;
	return OOB(x, y);
}

//물고기 이동함수
void MoveFish() {
	for (int i = 1; i <= 16; i++) {
		if (!isFishLive[i]) continue;
		bool canMove = true; // 물고기가 움직일 수 있는지 판단.
		int direction = fishes[i].dir;  
		int firstdir = fishes[i].dir; // 물고기 초기 방향 확인 (한바퀴 다돌아도 못움직일 때 대비)
		int nx = fishes[i].x + dx[direction]; // 물고기가 이동할 좌표 설정
		int ny = fishes[i].y + dy[direction];

		while (CantMove(nx, ny)) { //움직일 수 없으면 방향 반시계로 돌림
			direction = (direction + 1) % 8; // 방향 반시계로 돌림
			if (direction == firstdir) { // 처음 방향과 같아지면 못움직이는 것
				canMove = false;  
				break;
			}
			nx = fishes[i].x + dx[direction]; // 좌표 수정
			ny = fishes[i].y + dy[direction]; 
		}

		// 못움직이는 상태면 다음 물고기 확인
		if (!canMove) continue;

		//물고기 방향 수정
		fishes[i].dir = direction;
		pair<int, int> curFish = {fishes[i].x,fishes[i].y}; // swap을 위한 물고기 위치 저장

		
		if (board[nx][ny] != 0) { // 물고기 좌표 교환
			swap(fishes[board[nx][ny]].x, fishes[i].x);	 
			swap(fishes[board[nx][ny]].y, fishes[i].y);  
		}
		else { // 판이 0이면 해당 칸은 물고기의 정보를 swap해 줄 필요가 없음 
			fishes[i].x = nx;
			fishes[i].y = ny;
		}
		swap(board[curFish.X][curFish.Y], board[nx][ny]); //물고기 판 수정
	}
}


void Shark_Eat(int sum) {
	answer = max(sum, answer); // answer 갱신
	Shark tmp = shark; // 초기 상어 정보 저장
	int copyBoard[4][4];
	Fish copyFishes[17];
	Copy(copyBoard, board, copyFishes, fishes);
	MoveFish();
	for (int i = 1;; i++) {
		int	nx = shark.x + dx[shark.dir] * i; // i를 1씩 증가시키며 상어 위치 갱신
		int ny = shark.y + dy[shark.dir] * i;

		if (OOB(nx, ny)) break; // 범위 밖이면 종료
		if (board[nx][ny] == 0) continue; // 판이 0이면 더 가야한다.

		int idx = board[nx][ny]; // 판 정보 저장
		isFishLive[board[nx][ny]] = false; // 해당칸의 물고기 죽음
		shark.x = nx; // 상어의 위치를 해당 칸으로 수정
		shark.y = ny;
		shark.dir = fishes[board[nx][ny]].dir; // 상어 방향 수정
		board[nx][ny] = 0; // 판 수정
		Shark_Eat(sum + idx); // 해당 물고기의 번호를 더해주고 다음 깊이 탐색ㄷ
		shark = tmp; // 탐색이 다 끝나면 상어 정보를 초기값으로 변경
		board[nx][ny] = idx; // 판도 초기값으로 변경
		isFishLive[board[nx][ny]] = 1; //물고기 다시 부활
	}
	Copy(board, copyBoard, fishes, copyFishes);
}
	

void solution() {
	Shark_Eat(answer);
	cout << answer <<"\n";	
}

int main() {
	init();
	input(); 
	solution();
}
