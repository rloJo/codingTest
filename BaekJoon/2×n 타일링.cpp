#include <iostream>

using namespace std;

int n;
int dp[1002];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i-1]+dp[i-2]) % 10007;
	}
	
	cout << dp[n];

	return 0;
}
