#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(vector<string> &want, vector<int> number, vector<string>&discount, int st) {
    for (int i = st; i < st + 10;i++) {
        for (int j = 0; j < want.size(); j++) {
            if (want[j] == discount[i]) {
                number[j]--;
                break;
            }
        }
    }

    for (int k = 0; k < number.size(); k++) {
        if (number[k] < 0 || number[k] > 0) return false;
    }
   
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for (int i = 0; i < discount.size()-9; i++) {
        if (check(want, number, discount, i)) answer++;
    }

    return answer;
}
