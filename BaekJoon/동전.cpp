#include <iostream>

using namespace std;

int T, N,M;
int coin[22];
long long dp[10002];

void init_dp() { //dp 배열 초기화
	for (int i = 0; i <= M; i++)
		dp[i] = 0;
	dp[0] = 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while(T--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> coin[i];
		cin >> M;
		init_dp();
		for (int i = 0; i < N; i++) {
			for (int j = coin[i]; j <= M; j++) { //coin[i]부터 시작해야 중복 방지할수있다.
				dp[j] += dp[j - coin[i]]; // j가  5 coin[i] =3 일때
											// dp[5] = dp[2] 2원을 만드는 법을 더해야 5 만들 수 있음
			}
		}

		cout << dp[M] << "\n";
	}

	return 0;
}
