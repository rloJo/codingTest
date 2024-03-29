#include <iostream>

using namespace std;

int K, N;
int graph[100002][4];
int dp[100002][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1) {
		K++;
		cin >> N;
		if (!N) break;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= 3; j++)
				cin >> graph[i][j];


		// 첫번째 줄 값 넣기 
		// dp[1][1]은 못가는 경우 => 큰 수로 대체
		dp[1][2] = graph[1][2];
		dp[1][3] = graph[1][2] + graph[1][3];
		dp[1][1] = 1000000;
		for (int i = 2; i <= N; i++) {
			dp[i][1] = min(dp[i - 1][1], dp[i - 1][2]) + graph[i][1];
			dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][2]), min(dp[i - 1][3], dp[i][1])) + graph[i][2];
			dp[i][3] = min(min(dp[i - 1][2], dp[i - 1][3]), dp[i][2]) + graph[i][3];
		}
		//2 번 줄부터 각 경우
		//1번 열의 경우 위에서 바로 내려오는 경우와 중간에서 오는 경우 2가지 경우
		//2번 열의 경우 왼 가 오 세개에서 내려오는 경우 + 자신의 왼쪽에서 오는 경우로 4가지 경우
		//3번 열의 경우 가운데, 오른쪽에서 내려오는 경우 및 자신의 왼쪽 에서 오는 경우 3가지 이다.

		cout << K << ". " << dp[N][2] << "\n";
	}


	return 0;
}
