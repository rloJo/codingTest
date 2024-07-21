#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a.back() < b.back();
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int cur = 0;
    sort(targets.begin(), targets.end(),cmp);
    for (int i = 0; i < targets.size(); i++) {
        if (cur > targets[i][0]) continue;
        cur = targets[i][1];
        answer++;
    }

    return answer;
}
