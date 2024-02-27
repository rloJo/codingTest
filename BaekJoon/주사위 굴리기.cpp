#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second
/*
크기가 N×M인 지도가 존재한다. 지도의 오른쪽은 동쪽, 위쪽은 북쪽이다. 이 지도의 위에 주사위가 하나 놓여져 있으며, 주사위의 전개도는 아래와 같다. 지도의 좌표는 (r, c)로 나타내며, r는 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로부터 떨어진 칸의 개수이다.

  2
4 1 3
  5
  6

주사위는 지도 위에 윗 면이 1이고, 동쪽을 바라보는 방향이 3인 상태로 놓여져 있으며, 놓여져 있는 곳의 좌표는 (x, y) 이다.
가장 처음에 주사위에는 모든 면에 0이 적혀져 있다.
지도의 각 칸에는 정수가 하나씩 쓰여져 있다. 
주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
주사위를 놓은 곳의 좌표와 이동시키는 명령이 주어졌을 때, 주사위가 이동했을 때 마다 상단에 쓰여 있는 값을 구하는 프로그램을 작성하시오.
주사위는 지도의 바깥으로 이동시킬 수 없다. 
만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다.

입력

첫째 줄에 지도의 세로 크기 N, 가로 크기 M (1 ≤ N, M ≤ 20),
주사위를 놓은 곳의 좌표 x, y(0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1), 
그리고 명령의 개수 K (1 ≤ K ≤ 1,000)가 주어진다.

둘째 줄부터 N개의 줄에 지도에 쓰여 있는 수가 북쪽부터 남쪽으로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다. 
주사위를 놓은 칸에 쓰여 있는 수는 항상 0이다. 
지도의 각 칸에 쓰여 있는 수는 10 미만의 자연수 또는 0이다.
마지막 줄에는 이동하는 명령이 순서대로 주어진다.
동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다.
*/

using namespace std;

int N, M, K;
pair<int, int> dice; // 주사위 좌표
int map[22][22];
vector<pair<int, int>> dr { {4,0}, {1,0},{ 3,0} }; // 주사위 전개도 가로 //처음 모든 눈은 0
vector<pair<int, int>> dc { {2,0},{1,0},{5,0},{6,0} }; // 주사위 전개도 세로
// 바닥은 dc[3] , 상단 dc[1] or dr[1]

void north() { // 북쪽으로 주사위 roll
	rotate(dc.begin(), dc.begin() + 1, dc.end());
	dr[1] = dc[1];
}

void south() { //남쪽으로 주사위 roll
	rotate(dc.begin(), dc.begin() + 3, dc.end());
	dr[1] = dc[1];
}

void east() { //동쪽으로 주사위 roll
	rotate(dr.begin(), dr.begin() + 2, dr.end());
	swap(dr[0], dc[3]);
	dc[1] = dr[1];
}

void west() { //서쪽으로 주사위 roll
	rotate(dr.begin(), dr.begin() + 1, dr.end());
	swap(dr[2], dc[3]);
	dc[1] = dr[1];
}

void check(int dir){ //주사위 바닥면과 지도를 비교하여 주사위 및 지도 설정
	if (dice.X < 0 || dice.X >= N || dice.Y < 0 || dice.Y >= M)
	{
		if(dir == 1) dice.Y--;
		if(dir == 2) dice.Y++;
		if (dir == 3) dice.X++;
		if (dir == 4) dice.X--;
		return;
	}
	
	if (dir == 1) east();
	if (dir == 2) west();
	if (dir == 3) north();
	if (dir == 4) south();

	if (map[dice.X][dice.Y] == 0) // 지도가 0이면
		map[dice.X][dice.Y] = dc[3].second; // 지도 값에 주사위 바닥 값 추가
	
	else { // 지도가 0이 아니면 
		dc[3].second= map[dice.X][dice.Y]; //주사위 바닥에 지도값 설정
		map[dice.X][dice.Y] = 0; // 지도 0으로 수정
	}

	cout << dc[1].second << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> dice.X >> dice.Y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (K--) {
		int instruction;
		cin >> instruction; // 동 1 서 2 북 3 남 4
		switch (instruction)
		{
		case 1:
			dice.Y++;
			check(instruction);
			break;
		case 2:
			dice.Y--;
			check(instruction);
			break;
		case 3:
			dice.X--;
			check(instruction);
			break;
		
		case 4:
			dice.X++;
			check(instruction);
			break;
		}
	}
	return 0;
}
