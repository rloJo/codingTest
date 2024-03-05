#include <iostream>

/*
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.

정사각형은 서로 겹치면 안 된다.
도형은 모두 연결되어 있어야 한다.
정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.
정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.

아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 
종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.
테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.
테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.
*/
using namespace std;

int N, M;
int board[502][502]; // 보드 배열
int ans = -1; // 정답 변수

int tetro[7][4][4];
// 각 도형의 크기 저장 0-> ㅡ 모양 1 -> ㅁ 모양 2-> L 모양 3-> L대칭 4- >z 모양 5->z 대칭 6-> ㅜ 모양
pair<int, int> s[7] = { {1,4},{2,2},{3,2},{3,2},{3,2},{ 3,2 },{2,3} };
int cnt[7] = {2,1,5,5,2,2,5}; // 각 도형을 몇번 돌려야 원래 모양이 나오는지

void turn(int idx) { // 테트로미노 90도 회전
	int tmp[4][4];
	for (int i = 0; i < s[idx].first; i++)
		for (int j = 0; j < s[idx].second; j++)
			tmp[i][j] = tetro[idx][i][j];

	for (int i = 0; i < s[idx].second; i++)
		for (int j = 0; j < s[idx].first; j++)
			tetro[idx][i][j] = tmp[s[idx].first -1 -j][i];

	swap(s[idx].first, s[idx].second);
}

void check(int idx) {
	int sum = 0;
	for (int k = 0; k < cnt[idx]; k++) // 특정 도형은 안돌리거나 1회전만 해도 상관 없음 
	{
		for (int i = 0; i <= N - s[idx].first; i++)
		{
			for (int j = 0; j <= M - s[idx].second; j++) {
				sum = 0;
				for (int ii = 0; ii < s[idx].first; ii++) {
					for (int jj = 0; jj < s[idx].second; jj++) {
						if (tetro[idx][ii][jj] == 1)
							sum += board[i + ii][j + jj];
					}
				}
				ans = max(ans, sum);
			}
		}
	turn(idx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j]; 

	for (int i = 0; i < 4; i++)  // ㅡ 모양 블록 idx 0
		tetro[0][0][i] = 1;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			tetro[1][i][j] = 1;  // ㅁ 모양 블록 idx 1 

	for (int i = 0; i < 3; i++)
		tetro[2][i][0] = 1;
	tetro[2][2][1] = 1;          // L모양 블록 idx 2

	for (int i = 0; i < 3; i++)
		tetro[3][i][1] = 1;
	tetro[3][2][0] = 1;          // L 대칭 모양 블록 idx 3

	tetro[4][0][0] = 1; tetro[4][1][0] = 1;
	tetro[4][1][1] = 1; tetro[4][2][1] = 1; // z모양 블록 idx 4

	tetro[5][0][1] = 1; tetro[5][1][1] = 1;
	tetro[5][1][0] = 1; tetro[5][2][0] = 1; // z 대칭 모양 블록 idx 5

	for (int i = 0; i < 3; i++) 
		tetro[6][0][i] = 1;
	tetro[6][1][1] = 1;         // ㅜ 모양 블록 idx 6

	for (int i = 0; i < 7; i++)
		check(i);

	cout << ans << "\n";
	return 0;
}
