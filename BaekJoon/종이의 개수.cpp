#include <iostream>

/*
N×N크기의 행렬로 표현되는 종이가 있다. 
종이의 각 칸에는 -1, 0, 1 중 하나가 저장되어 있다. 
우리는 이 행렬을 다음과 같은 규칙에 따라 적절한 크기로 자르려고 한다.

1. 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
2. (1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수,
1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

첫째 줄에 N(1 ≤ N ≤ 37, N은 3k 꼴)이 주어진다. 
다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

*/

using namespace std;

int N;
int ans[3]; //정답을 받을 배열
int map[2200][2200];

// 행렬의 시작 좌표를 얻어 해당 좌표의 카드가 모두 동일한지 검사
bool check(int row, int col, int size) {
	int tmp = map[row][col];
	for (int i = row; i <row + size; i++) {
		for (int j = col; j < col +size; j++) {
			if (tmp != map[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void recur(int row, int col, int n) {
	if (check(row, col, n)) { //모두 같은 카드면
		ans[map[row][col]]++; // 해당 카드 수 1증가
	}
	else {
		int size = n / 3; //다르면 n을 3으로 나눈 수를 재귀 돌린다
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				recur(row + size * i, col + size * j, size);
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			map[i][j]++; //-1,0,1 을 배열을 사용하기 위해 +1씩 해서 0,1,2
		}
	}
	recur(0, 0, N);
	cout << ans[0] << "\n" << ans[1] <<"\n" << ans[2];


}
