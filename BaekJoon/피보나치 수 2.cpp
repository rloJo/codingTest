#include <iostream>

using namespace std;

long long dp[92];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];

	return 0;
}
