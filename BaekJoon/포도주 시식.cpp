#include <iostream>

using namespace std;

int n;
int wine[10002];
int dp[10002]; //[N]번째 까지 마신 것중에 최대

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wine[i];

	dp[1] = wine[1]; // 1번 와인의 최대는 1번 와인을 마신것
	dp[2] = wine[1] + wine[2]; //2번와인의 최대는 2번 와인과 1번 와인을 마신것
	for (int i = 3; i <= n; i++) 
		dp[i] = max(dp[i - 1], max(dp[i - 2] + wine[i], dp[i - 3] + wine[i] + wine[i - 1]));
	// 3번 부터는 3개를 연속으로 마실 수 없으므로
	// 2번 까지 최대로 마신 것, 1번 까지 최대로 마신것 + 3번 와인을 마신것, 자신의 이전와인 2번와인 과 3번와인을 마신것
	// 위 3가지 중에 최대값이 된다.

	cout << dp[n];
	return 0;
}
