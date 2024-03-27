#include <iostream>

using namespace std;

int N;
int P[1002];
int dp[1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> P[i];

	// dp[N]은 dp[N-(1~N)] 까지 최대값 + P[(1~N)]의 가격의 최댓값이다
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + P[j]);
		}
	}

	cout << dp[N] << "\n";

	return 0;
}
