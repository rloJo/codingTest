#include <iostream>

using namespace std;

int T,N;
int arr[1002];
int dp[1002];
int ans = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		dp[i] = arr[i];
		for (int j = 0; j <= i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + arr[i]);
			ans = max(ans, dp[i]);
		}
	}

	cout << ans << " ";
	return 0;
}
