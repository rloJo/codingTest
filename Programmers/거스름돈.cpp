#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int dp[100002] = { 0 };

int solution(int n, vector<int> money) {
    dp[0] = 1;

    for (int m : money) {
        for (int i = m; i <= n; i++) {
            dp[i] += dp[i - m];
            dp[i] %= MOD;
        }
    }

    return dp[n];
}
