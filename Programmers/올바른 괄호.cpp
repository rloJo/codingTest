#include<string>
#include <iostream>
#include<stack>

using namespace std;

bool check(string s) {
    stack<char> open;
    for (auto c : s) {
        if (c == '(') open.push('(');
        else {
            if (open.empty()) return false;
            else open.pop();
        }
    }

    return open.empty();
}

bool solution(string s)
{
    bool answer = check(s);
    return answer;
}
