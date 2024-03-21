#include <iostream>

using namespace std;

string first;
string second;
int dp[1002][1002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> first >> second;
	
	for (int i = 1; i <= second.length(); i++) {
		for (int j = 1; j <= first.length(); j++) {
			if (second[i - 1] == first[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			// 문자가 같으면 왼쪽 대각선 위에서 +1 한 값 가져옴
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			// 다르면 위 또는 뒤에서 max값
		}
	}

	cout << dp[second.length()][first.length()];

	return 0;
}
