#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;

long long dp[5002] = { 0 };

int solution(int n) {
    dp[0] = 1;
    dp[2] = 3;
    if (n % 2) return 0;
    for (int i = 4; i <= n; i+=2) {
        dp[i] = dp[i - 2] * 3; // dp[2]가 3가지 경우니까 줄세우는 경우의수 
        for (int j = i - 4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2; // 특이한 모양 2개 4일때 부터 2개가 나옴
        }
        dp[i] %= MOD;
    }
    return dp[n];
}
