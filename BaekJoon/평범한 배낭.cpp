#include <iostream>

using namespace std;

int N, K;
int w[102]; //물건의 무게
int v[102]; //물건의 가치
int dp[100002][102]; // dp[N][i]는 i번째 까지 갔을 때 가치의 최대

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= w[i]) // 현재 무게가 가방을 담을 수 있으면
				dp[j][i] = max(dp[j - w[i]][i - 1] + v[i], dp[j][i - 1]);
				// (현재 무게 - 가방의 무게)일 떄의 최대 가치 + 해당 가방의 가치
				// 가방을 안들고 이전 가방까지 최대 가치 비교
			else
				dp[j][i] = dp[j][i - 1];
			// 현재 무게를 못담으면 이전 가방까지의 최대 가치 삽입
		}
	}

	cout << dp[K][N];

	return 0;
}
