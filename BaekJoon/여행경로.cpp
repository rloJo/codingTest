#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool used[10002] = { false };
vector<string> answer;

bool DFS(string start, int cnt, vector<vector<string>>& tickets) {
    answer.push_back(start);
    if (cnt == tickets.size()) return true;
    for (int i = 0; i < tickets.size(); i++) {
        if (used[i]) continue;
        if (tickets[i][0] != start)  continue;
        used[i] = true;
        if(DFS(tickets[i][1], cnt + 1, tickets)) return true;
        used[i] = false;
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end());
    DFS("ICN",0, tickets);
    return answer;
}
