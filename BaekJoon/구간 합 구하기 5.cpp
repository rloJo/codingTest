#include <iostream>
#define X first
#define Y second
using namespace std;

int N, M;
int chart[1026][1026];
int dp[1026][1026];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sum = 0;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> chart[i][j];
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + chart[i][j];
			//2 차원 배열 누적합을 더해준다
		}
	}

	while (M--) {
		int ans = 0;
		pair<int, int> start, end;
		cin >> start.X >> start.Y >> end.X >> end.Y;
		cout << dp[end.X][end.Y] - dp[end.X][start.Y - 1] - dp[start.X - 1][end.Y] + dp[start.X - 1][start.Y - 1] << "\n";
		// 해당 구간 계산
	}

	return 0;
}
