#include <iostream>

using namespace std;

int N, M;
int map[1002][1002];
int dp[1002][1002][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	//<|>
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 3; j++)
			dp[1][i][j] = map[1][i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (j == 1) {
				dp[i][j][1] = dp[i - 1][j + 1][0] + map[i][j];
				dp[i][j][2] = min(dp[i - 1][j][1],dp[i-1][j+1][0]) + map[i][j];
			}
			else if (j == M) {
				dp[i][j][0] = min(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + map[i][j];
				dp[i][j][1] = dp[i - 1][j-1][2] + map[i][j];
			}
			else {
				dp[i][j][0] = min(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + map[i][j];
				dp[i][j][1] = min(dp[i - 1][j+1][0], dp[i - 1][j-1][2]) + map[i][j];
				dp[i][j][2] = min(dp[i - 1][j+1][0] , dp[i - 1][j][1]) + map[i][j];
			}
		}
	}

	int ans = 2000000000;

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 3; j++) {
			if (!dp[N][i][j]) continue;
			ans = min(dp[N][i][j], ans);
		}
	}

	cout << ans;
	
	return 0;
}

