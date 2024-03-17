#include <iostream>

using namespace std;

int N,T;
int dp[12];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	
	while (T--) {
		cin >> N;
		cout << dp[N] << "\n";
	}

	return 0;
}
