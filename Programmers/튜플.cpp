#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> tp;

void find_tuple(string s) {
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == s.size() - 1) tp[stoi(tmp)]++;
        if (s[i] == '{' || s[i] == '}') continue;
        if (s[i] == ',') {
            tp[stoi(tmp)] ++;
            tmp = "";
        }
        else tmp += s[i];
    }
}

vector<int> solution(string s) {
    vector<pair<int,int>> sorting;
    vector<int> answer;
    find_tuple(s);
    for (auto c : tp) {
        sorting.push_back({c.second, c.first});
    }
    sort(sorting.begin(), sorting.end(), greater<>());
    for (auto c : sorting) {
        answer.push_back(c.second);
    }
    return answer;
}


