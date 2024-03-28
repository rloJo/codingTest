#include <iostream>

using namespace std;

int n, k;
int coin[102];
int dp[10002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	//dp[N] 은 N원을 만드는 경우의 수
	//dp[N] = dp[N-coin]의 경우읫 수 이다
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[k] << "\n";

	return 0;
}
