#include <string>
#include <vector>
#include <stack>

using namespace std;

bool alpha[26] = { false };

bool checkCanLearn(stack<char>st, string skill) {
    for (char c : skill) {
        if (!alpha[c - 'A']) continue;
        if (st.top() != c) return false;
        else st.pop();
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    stack <char> st;
    int answer = 0;
    for (int i = skill.size() - 1; i >= 0; i--) {
        alpha[skill[i] - 'A'] = true;
        st.push(skill[i]);
    }
    
    for (int i = 0; i < skill_trees.size(); i++) {
        answer += checkCanLearn(st, skill_trees[i]);
    }

    return answer;
}
