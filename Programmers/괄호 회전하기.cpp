#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool check(string s, int size) {
    stack<char> stk;

    for (int i = 0; i < size; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
        if (s[i] == ')') {
            if (stk.empty()) return false;
            if (stk.top() == '(') stk.pop();
            else return false;
        }
        else if (s[i] == ']') {
            if (stk.empty()) return false;
            if (stk.top() == '[') stk.pop();
            else return false;
        }
        else if (s[i]=='}') {
            if (stk.empty()) return false;
            if (stk.top() == '{') stk.pop();
            else return false;
        }
    }

    return stk.empty();
}

int solution(string s) {
    int answer = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        if(check(s,size)) answer++;
        s.push_back(s[0]);
        s.erase(0, 1);
    }
    return answer;
}
