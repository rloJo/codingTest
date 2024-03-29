#include <iostream>

using namespace std;

int N;
int cost[1002][3]; // RGB순
int dp[1002][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];

	dp[1][0] = cost[1][0]; 
	dp[1][1] = cost[1][1]; 
	dp[1][2] = cost[1][2]; 

	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);

	return 0;
}
