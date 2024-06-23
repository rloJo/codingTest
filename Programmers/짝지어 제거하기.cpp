#include <iostream>
#include<string>
#include <stack>

using namespace std;

bool EliminatePair(string s) {
    stack<char> str;
    str.push(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (!str.empty() && str.top() == s[i]) str.pop();
        else str.push(s[i]);
    }

    return str.empty();
}

int solution(string s)
{
   return EliminatePair(s);
}
