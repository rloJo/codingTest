#include <iostream>
using namespace std;

int T;
int N;
int dp[10001][4];
//dp[N][1~3] 
//dp[N][1] N을 만들 때 1 로 끝나는 경우 1 + 1 + 1 ...
//dp[N][2] N을 만들 때 2 로 끝나는 경우 1 + 1 + 2, 2+2  ...
//dp[N][3] N을 만들 때 3 으로 끝나는 경우 1 + 1 + 1 + 3 , 2+3, 3+3...
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[0][1] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 10000; i++) {
		dp[i][1] = dp[i-1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		if (i >= 3)
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}
	cin >> T;
	
	while (T--) {
		cin >> N;
		cout << dp[N][1] + dp[N][2] + dp[N][3] << "\n";
	}
	return 0;
}

