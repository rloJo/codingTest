#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[0] + a[1] > b[0] + b[1];
}


int solution(vector<vector<int>> scores) {
    int answer = 1; 

    sort(scores.begin()+1, scores.end(), cmp);

    for (int i = 1; i < scores.size();i++) {
        // 완호가 못받는경우
        if (scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1]) return -1;
        if (scores[0][0] + scores[0][1] < scores[i][0] + scores[i][1]) answer++;
        else break; // 같은경우는 셀필요없음 어짜피 등수에 영향 x
    }

    int wan = answer;

    for (int i = 2; i < wan; i++) {
        for (int j = 1; j < i; j++) {
            if (scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1]) {
                --answer;
                break;
            }
        }
    }

    return answer;
}
