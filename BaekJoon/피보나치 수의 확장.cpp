#include <iostream>

#define MOD 1000000000

using namespace std;

int n;
int dp[1000002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	dp[0] = 0; dp[1] = 1;
	
	// n이 음수 + 짝수이면 절대값 n의 값에 -가 붙여서 나옴
	// 홀수이면 절대값 n과 똑같이 나옴
	for (int i = 2; i <= abs(n); i++)
		dp[i] = (dp[i - 1] + dp[i - 2])%MOD;

	if (n > 0) cout << 1 << "\n";
	else if (n == 0) cout << 0 << "\n";
	else {
		if (abs(n) % 2 == 0)
			cout << -1 << "\n";
		else
			cout << 1 << "\n";
	}

	cout << dp[abs(n)];

	return 0;
}
