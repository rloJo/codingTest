#include <string>
#include <vector>
#define MOD 1234567

using namespace std;

int dp[2002];
int dp_find(int n) {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) %MOD;
    }
    return dp[n];
}

int solution(int n) {
    int answer = 0;
    answer = dp_find(n);
    return answer;
}
