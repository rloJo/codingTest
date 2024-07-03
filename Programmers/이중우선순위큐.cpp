#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
deque<int> dq;

void operate(string op) {
    string o = op.substr(0,1);
    int num = stoi(op.substr(op.find(' ')));
    if (o == "I") {
        dq.push_back(num);
        sort(dq.begin(), dq.end());
    }
    else if (o == "D") {
        if (!dq.empty())
        {
            if (num == -1) {
                dq.pop_front();
            }
            else if (num == 1) { 
                dq.pop_back();
            }
        }
    }
}

vector<int> solution(vector<string> operations) {
    for (string c : operations) {
        operate(c);
    }
    if (dq.empty()) return { 0,0 };
    else return { dq.back(), dq.front() };

}
