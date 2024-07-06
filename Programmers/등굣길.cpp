#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int dp[102][102] = { 0 };

void Find_Min_Way(int m, int n, vector<vector<int>>& puddles) {
    for (int i = 0; i < puddles.size(); i++)
        dp[puddles[i][1]][puddles[i][0]] = -1;

    dp[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (dp[i][j] == -1) continue;
            int fromUp = dp[i - 1][j] == -1 ? 0 : dp[i - 1][j];
            int fromLeft = dp[i][j - 1] == -1 ? 0 : dp[i][j - 1];
            dp[i][j] = (fromLeft + fromUp) % MOD;
        }
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    Find_Min_Way(m, n, puddles);
    return dp[n][m];
}
