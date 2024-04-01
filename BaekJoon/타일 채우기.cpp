#include <iostream>

using namespace std;

int N;
int dp[32];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	//N이 홀수인 경우는 불가능하다.
	if (N % 2 == 1) {
		cout << "0" << "\n";
		return 0;
	}

	dp[0] = 1; dp[1] = 0; dp[2] = 3;
	
	//N의 경우의 수는 마지막에 n-2개를 놓고 3x2 타일을 마지막에 놓는 경우의 수 + 특수 경우의 수 이다
	//N = 4로 예시를 들면
	// N이 2일 때 놓는 경우의 수 * 3 = 9
	// + 특수 경우의 수 2개 즉, 11
	//N이 6일 때 놓는 경우의 수는
	//N이 2일 때 놓는 경우의 수가 마지막에 오는 경우
	//N이 4일 때 놓는 특수한 경우가 마지막에 오는 경우
	//특수한경우
	//즉, dp[6] = dp[4] * 3 + dp[2] *2 + dp[0] * 2
 
	for (int i = 4; i <= N; i+=2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = i-4; j >= 0; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}

	cout << dp[N] << "\n";

	return 0;
}
