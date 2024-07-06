#include <string>
#include <vector>
#define Max 1000000
using namespace std;

int dp[1000002] = { 0 };

void find_min(int x, int y, int n) {
    dp[x] = 0;
    for (int i = x; i <= y; i++) {
        if (dp[i] == Max) continue;
        if(i+n <=y)
          dp[i + n] = min(dp[i + n], dp[i] + 1);
        if(i*2 <=y)
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        if(i*3 <=y)
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }
}

int solution(int x, int y, int n) {
    for (int i = 0; i <= y; i++) dp[i] = Max;
    find_min(x, y, n);
    if (dp[y] == Max) return -1;
    return dp[y];
}
