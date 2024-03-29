#include <iostream>

using namespace std;

int T,n;
int sticker[3][100002];
int dp[3][100002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> n;
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> sticker[i][j];

		//1,1 스티커를 제거할 때 점수
		dp[1][1] = sticker[1][1];
		dp[2][1] = sticker[2][1];

		for (int i = 2; i <= n; i++) {
			//1,i의 스티커를 제거할 때 경우의 수는 자기 앞칸의 2 행을 뜯었을 때와 
			//자기의 앞 두칸의 2행을 제거하고 이걸 뜯는 경우의 수 2가지
			dp[1][i] = max(dp[2][i - 1], dp[2][i - 2]) + sticker[1][i];
			dp[2][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[2][i];
		}
		cout << max(dp[1][n], dp[2][n]) <<"\n";
	}

	return 0;
}
