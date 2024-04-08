#include <iostream>
#define MOD 10007

using namespace std;

int N, K;
int dp[1002][1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//nCombk = n-1CombK-1 + n-1CombK 
	cin >> N >> K;
	for (int i = 1; i <= 1000; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j=1;j<i;j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
		}
	}

	cout << dp[N][K];
	
	return 0;
}
