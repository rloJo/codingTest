#include <string>
#include <vector>
#include <stack>

using namespace std;

int binaryStepOne(string s) {
    int cnt = 0;
    for (char c : s)
        if (c-'0') cnt++;

    return cnt;
}

string binaryStepTwo(int cnt) {
    string n = "";
    stack<bool> mod;
    while (cnt > 0) {
        mod.push(cnt % 2);
        cnt /= 2;
    }

    while (!mod.empty()) {
        if (mod.top()) n += "1";
        else n += "0";
        mod.pop();
    }

    return n;
}

vector<int> solution(string s) {

    int DestroyedZeroCount = 0;
    int BinaryStepCount = 0;

    while (1) {
        int StrOneCount = binaryStepOne(s);
        DestroyedZeroCount += s.length() - StrOneCount;
        s = binaryStepTwo(StrOneCount);
        BinaryStepCount++;
        if (s == "1") break;
    }

    vector<int> answer;

    answer.push_back(BinaryStepCount);
    answer.push_back(DestroyedZeroCount);
    
    return answer;
}
