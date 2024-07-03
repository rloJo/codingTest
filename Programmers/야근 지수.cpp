#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> Q;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    for (int i = 0; i < works.size(); i++) Q.push(works[i]);
    while (n-- && !Q.empty()) {
        int work = Q.top();
        Q.pop();
        if (work > 1) Q.push(work - 1);
    }

    while (!Q.empty()) {
        answer += Q.top() * Q.top();
        Q.pop();
    }

    return answer;
}
