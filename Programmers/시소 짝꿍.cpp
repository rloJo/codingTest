#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long cnt[1001];

long long solution(vector<int> weights) {

    long long answer = 0;
    for (int weight : weights) cnt[weight]++;
   
    for (int weight : weights) {
        // 2 : 3 비
        if (weight % 2 == 0) {
            int base = (weight / 2) * 3;
            if (base <= 1000) answer +=  cnt[base];
        }
        // 3 : 4 비
        if (weight % 3 == 0) {
            int base = (weight / 3) * 4;
            if (base <= 1000) answer +=  cnt[base];
        }
        // 2 : 4 -> 1 : 2 비
        int base = weight * 2;
        if (base <= 1000) answer +=  cnt[base];
    }

    for (int i = 100; i <= 1000;i++) {
        if (cnt[i] < 2) continue;
        answer += (cnt[i] * (cnt[i] - 1)) / 2;
    }

    return answer;
}
