#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

string str[2] = { "님이 들어왔습니다.", "님이 나갔습니다." };
unordered_map <string, string> id;

void set_id(vector<string>& records, vector<pair<string, int>>& output) {
    for (int i = 0; i < records.size(); i++) {
        string input = records[i];
        string instruction;
        string uid;
        string name;
        stringstream ss(input);
        cout << instruction << " " << uid << " " << name;
        ss >> instruction >> uid >> name;
        id[uid] = name;
        if (instruction == "Enter") output.push_back({ uid,0 });
        if (instruction == "Leave") output.push_back({ uid,1 });
    }
}

vector<string> solution(vector<string> record) {
    vector<pair<string, int>> output;
    vector<string> answer;
    set_id(record, output);
    for (int i = 0; i < output.size(); i++) {
        string result = id[output[i].first] + str[output[i].second];
        answer.push_back(result);
    }

    return answer;
}
