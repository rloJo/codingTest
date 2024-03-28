#include <iostream>
#define MOD 15746

using namespace std;

int N;
int dp[1000002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;

	dp[1] = 1; dp[2] = 2;

	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  //00이 앞에오는 경우 + 1이 앞에오는 경우를 더해준다
	cout << dp[N] << "\n";

	return 0;
}
