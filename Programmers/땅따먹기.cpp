#include <iostream>
#include <vector>
using namespace std;

int dp[100002][4] = { 0 };

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for (int i = 0; i < land[0].size(); i++) {
        dp[0][i] = land[0][i];
    }

    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            for (int k = 0; k < land[i].size(); k++) {
                if (j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + land[i][j]);
            }
        }
    }

    for (int i = 0; i < land[0].size(); i++) {
        cout << dp[land.size() - 1][i] << " ";
        answer = max(answer, dp[land.size() - 1][i]);
    }

    return answer;
}
