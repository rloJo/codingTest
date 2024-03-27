#include <iostream>
#define MOD 10007

using namespace std;

int N;
int dp[1002][10];
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	//dp[N][0~9] 는 N자리 오르막 수 중에 마지막이 [0~9]로 끝나는 오르막수의 개수
	//dp[N][9] 의 개수는 dp[N-1][0] ~ dp[N-1][9]의 값을 모두 더한 것과 같음
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for(int k=0;k<=j;k++){
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= MOD;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		ans += dp[N][i];
		ans %= MOD;
	}

	cout << ans << "\n";

	return 0;
}
