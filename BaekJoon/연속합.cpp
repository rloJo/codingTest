#include <iostream>

using namespace std;

int T,N;
int arr[100002];
int dp[100002];
int ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	ans = dp[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		ans = max(dp[i], ans);
	}

	cout << ans << " ";
	return 0;
}
