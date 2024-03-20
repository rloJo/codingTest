#include <iostream>

using namespace std;

int N;
pair<int, int> plan[16]; //상담 걸리는 일, 금액 순
int dp[16];
int mx = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> plan[i].first >> plan[i].second;

	for (int i = 1; i <= N+1; i++) { //날짜
		dp[i] = max(dp[i], mx); // dp갱신
		
		//N+1인 이유 7일에 1일 짜리 일이 걸리면 8일부터 일을 시작 가능.
		// 따라서 N+1까지 검사해줘야한다
		if(plan[i].first + i <= N+1) // 기준 일보다 작아야 일이 가능하다
			dp[plan[i].first + i] = max(dp[plan[i].first+i], plan[i].second + dp[i]);
		
		mx = max(dp[i], mx); // 현재 까지 최대 금액
	}

	cout << mx << "\n";

	return 0;
}
