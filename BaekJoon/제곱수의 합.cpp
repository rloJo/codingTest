#include <iostream>

using namespace std;

int N;
int dp[100002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N];

	return 0;
}
