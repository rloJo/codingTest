#include <iostream>
#define MOD 1000000009

using namespace std;

int T, n;
long long dp[1000002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> T;

	dp[1] = 1; dp[2] = 2; dp[3] = 4;

	// 점화식 dp[n]은 
	// 1번째 로 1을 넣고 n-1을 세는 법 + 
	// 1번째로 2를 넣고 n-2를 세는 법 +
	// 1번 째로 3을 넣고 n-3을 세는 법
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}

	while (T--) {
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}
