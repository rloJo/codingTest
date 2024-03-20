#include <iostream>

#define Mod 1000000000
using namespace std;

int N;
long long dp[102][10]; 
// 자리수, 끝나는 자리가 ?일때 개수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1] % Mod;
		// 0으로 끝나는 수는 앞선 자리수의 마지막이 1일 때만 가능
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % Mod;
			//끝나는 수가 1~8 까지는 앞선 수의 끝자리 위 아래를 검사
			// ex ) 7 이면 6 8 검사
		}
		dp[i][9] = dp[i - 1][8] % Mod;
		//9가 끝자리 이면 뒤에 8만 올수 있음
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans = (ans + dp[N][i]) % Mod;
	}

	cout << ans;

	return 0;
}
