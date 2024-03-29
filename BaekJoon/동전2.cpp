#include <iostream>

using namespace std;

int n, k;
int coin[102];
int dp[10002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	for (int i = 1; i <= k; i++)
		dp[i] = 10001; //최댓값 삽입 최소 개수를 구하기 위한

	//동전 1 문제와 유사하지만 이것은 동전의 개수를 구하는 것
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j],dp[j - coin[i]] + 1); 
			// 자기 현재 상황과 동전으로 만들수있는 값 + 1 비교
		}
	}

	if (dp[k] == 10001) cout << -1;
	else cout << dp[k] << "\n";

	return 0;
}
