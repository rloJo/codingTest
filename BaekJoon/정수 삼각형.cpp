#include <iostream>

using namespace std;

int n;
int triangle[502][502];
int dp[502][502];
int ans = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
	dp[1][1] = triangle[1][1];
	ans = triangle[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			ans = max(dp[i][j], ans);
		}
	}
	cout << ans << "\n";
	return 0;
}
