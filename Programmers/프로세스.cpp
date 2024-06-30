#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
priority_queue<int> pq;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i = 0; i < priorities.size();i++) {
        q.push({ i,priorities[i]}); // {3,2} {0,2} {1,1} {2,3} {3,2}
        pq.push(priorities[i]); // 3,2,2,1
    }

    int cnt = 1;
    while (1) {
        pair<int, int> qfront = q.front();
        q.pop();
        if (qfront.second == pq.top()) {
            if (qfront.first == location) {
                answer = cnt;
                break;
            }
            else {
                pq.pop();
                cnt++;
            }
        }
        else if (qfront.second != pq.top()) {
            q.push({ qfront.first,qfront.second });
        }
    }
    return answer;
}
