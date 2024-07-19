#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int cur = 1;
    int idx = 0;
    int answer = 0;
    while (cur <= n) {
        if (cur >= stations[idx] - w && cur <= stations[idx] + w) {
            cur = stations[idx] + w;
            idx++;
        }
        else {
            answer++;
            cur += 2 * w;
        }
        cur++;
    }
    
    return answer;
}
