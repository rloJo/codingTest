#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;

int dp[60002] = { 0 };

void find_way(int n) {
    dp[1] = 1; dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

}

int solution(int n) {
    find_way(n);
    return dp[n];
}
