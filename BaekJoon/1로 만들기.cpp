#include <iostream>

using namespace std;

int N;
int dp[10000002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	dp[1] = 0;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
		if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
	}

	cout << dp[N];

	return 0;
}
