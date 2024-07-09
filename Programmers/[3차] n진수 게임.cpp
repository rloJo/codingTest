#include <string>
#include <vector>
#include <stack>

using namespace std;
string formation(int n,int num) {
    string format = "";
    stack<char> st;
    while (num > 0) {
        char mod = num % n;
        if (num % n == 10) mod = 'A';
        else if (num % n == 11) mod = 'B';
        else if (num % n == 12) mod = 'C';
        else if (num % n == 13) mod = 'D';
        else if (num % n == 14) mod = 'E';
        else if (num % n == 15) mod = 'F';
        else mod = (num % n) + '0';

        st.push(mod);
        num /= n;
    }
    while (!st.empty()) {
        format += st.top();
        st.pop();
    }
    return format;
}

string find_formation(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "-0";
    int start = 1;
    int turn = 0;
    
    while (answer.size() < t) {
        tmp += formation(n, start);
        start++;
        while (tmp.size() > turn * m + p) {
            if (answer.size() >= t) break;
            answer += tmp[turn * m + p];
            turn++;
        }
    }

    return answer;
}

string solution(int n, int t, int m, int p) {

    return find_formation(n, t, m, p);
}
