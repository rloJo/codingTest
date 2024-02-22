#include <iostream>
/*
2048 게임은 보드의 크기가 N×N 이다. 보드의 크기와 보드판의 블록 상태가 주어졌을 때, 
최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성하시오.

첫째 줄에 보드의 크기 N (1 ≤ N ≤ 20)이 주어진다. 
둘째 줄부터 N개의 줄에는 게임판의 초기 상태가 주어진다. 
0은 빈 칸을 나타내며, 이외의 값은 모두 블록을 나타낸다. 
블록에 쓰여 있는 수는 2보다 크거나 같고, 1024보다 작거나 같은 2의 제곱꼴이다. 
블록은 적어도 하나 주어진다.


*/

using namespace std;

int N;
int board1[22][22];
int board2[22][22];
int ans = -8;

void turn(){ //90도로 판 회전 상하좌우 다짜기 보다는 보드를 회전시키는게 편함
	int tmp[22][22];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			tmp[i][j] = board2[i][j];


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board2[i][j] = tmp[N-1-j][i];
}

void left(int dir) { //보드판을 왼쪽으로 밀었을 떄를 계산하는 함수 dir 에 따라 board를 90도 씩 회전 반복]
	while (dir--) turn();
	for (int i = 0; i < N; i++) {
		int tmp[22] {};
		int idx = 0;
		for (int j = 0; j < N; j++) {
			if (board2[i][j] == 0) continue; //해당 보드칸이 0이면 그냥 진행
			if (tmp[idx] == 0) //해당 보드칸이 0이아니고 끝자리가 0이면 
				tmp[idx] = board2[i][j]; //해당 끝자리에 숫자 넣기
			else if (tmp[idx] == board2[i][j]) //만약 끝자리와 보드의 수가 같으면
				tmp[idx++] *= 2; //2배 증가시키고 끝자리 인덱스 변경
			else //둘이 다를 경우 인덱스를 증가 시키고 숫자 넣기
				tmp[++idx] = board2[i][j];
		}
		for (int j = 0; j < N; j++) board2[i][j] = tmp[j];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board1[i][j];
	for (int tmp = 0; tmp < 1024; tmp++) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board2[i][j] = board1[i][j];
		int brute = tmp;
		for (int i = 0; i < 5; i++) {
			int dir = brute % 4;
			brute /= 4;
			left(dir);
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans = max(ans, board2[i][j]);

	}
	cout << ans;
	return 0;
}
