#include <iostream>

using namespace std;

int n, m;
int ans = 0;
int board[1002][1002];

// 검사를 할때 해당 점이 0이면 검사할 필요가 없고
// 0이 아니면 해당 점이 오른쪽 아래 끝점이라고 가정하고 검사
// 왼쪽 위쪽 왼쪽 대각선을 검사해서 해당 칸에서 나온 값중 최소값 + 1 값을 가지게 된다.


void check() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] != 0) {
				//왼쪽 위쪽 대각선 검사
				board[i][j] = min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])) + 1;
				ans = max(ans, board[i][j]);
			}
		}
	}

	cout << ans * ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i<= n; i++) {
		string tmp; 
		cin >> tmp;
		for(int j=0;j<m;j++)
			board[i][j+1] = tmp[j] -'0'; //문자를 정수형으로 변환
	}
	check();
	return 0;
}
