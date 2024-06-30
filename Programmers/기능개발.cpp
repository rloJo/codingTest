#include <string>
#include <vector>

using namespace std;

vector<int> Progress_check(vector<int>& progress, vector<int>& speeds) {
    int cur = 0;
    int end_cnt = 0;
    vector<int> answer;
    while (cur < progress.size()) {
        for (int i = cur; i < progress.size(); i++) {
            progress[i] += speeds[i];
        }
        if (progress[cur] < 100) continue;
        for (int i = cur; i < progress.size(); i++) {
            if (progress[i] >= 100) {
                end_cnt++;
                cur++;
            }
            else break;
        }
        answer.push_back(end_cnt);
        end_cnt = 0;
    }
    return answer;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    return Progress_check(progresses,speeds);
}
