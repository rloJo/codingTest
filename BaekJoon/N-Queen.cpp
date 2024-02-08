#include <iostream>

/*
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 N이 주어진다. (1 ≤ N < 15)
*/

using namespace std;
int N;
int cnt =0;
int vis_1[40]; // 열 검사하는 배열
int vis_2[40]; // 오른쪽으로 올라가는 대각선 검사하는 배열 x,y에 퀸이 있으면 x+y 를 못간다는 표시
int vis_3[40]; // 오른쪽으로 내려가는 대각선 검사하는 배열 x,y에 퀸이 있으면 x-y검사 인덱스가 음수를 방지하기 위해 n-1 추가

void BT(int cur) {
	if(cur==N){
		cnt++; // cnt 증가후 리턴
		return;
	}
	for (int i = 0; i < N; i++) {
		if (vis_1[i] || vis_2[i + cur] || vis_3[cur - i + N - 1]) //갈 곳이 하나라도 없다면 넘김
			continue;
		vis_1[i] = 1;
		vis_2[i + cur] = 1;
		vis_3[cur - i + N - 1] = 1;
		BT(cur + 1);
		vis_1[i] = 0;
		vis_2[i + cur] = 0;
		vis_3[cur - i + N - 1] =0;
 	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	BT(0);
	cout << cnt << "\n";
	return 0;
}
