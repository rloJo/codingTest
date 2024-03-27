#include <iostream>
#define MOD 1000000009

using namespace std;

int N, M;
int dp[42];
int vip[42];
int ans =1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M;

	for (int i = 1; i <= M; i++)
		cin >> vip[i];

	dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 3;
	
	//dp[N]은 1번째 좌석을 고정한 상태로 나머지를 앉히는 경우의수 +
	//맨 앞과 그 다음 사람 즉, 1,2번 좌석을 바꾸고 나머지를 앉히는 경우의 수
	// 따라서 dp[N] = dp[N-1] + dp[N-2]
	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	//고정석 까지의 좌석수를 계산해서 정답을 구한다
	int idx = 0;
	for (int i= 1; i <= M; i++) { 
		ans *= dp[vip[i] - idx -1];
		idx = vip[i];
	}

	ans *= dp[N - vip[M]];
	cout << ans;

	return 0;
}
