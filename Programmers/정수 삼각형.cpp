#include <string>
#include <vector>

using namespace std;

int dp[502][502] = { 0 };

void Set_dp(vector<vector<int>>& triangle) {
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < triangle[i].size(); j++) {
			if (j == 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
			else {
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
			}
		}
	}
}

int Find_Max(int size) {
	int answer = 0;
	for (int i = 0; i < size; i++) {
		answer = max(answer, dp[size][i]);
	}
	return answer;
}


int solution(vector<vector<int>> triangle) {
	Set_dp(triangle);
	return Find_Max(triangle.size()-1);
}
