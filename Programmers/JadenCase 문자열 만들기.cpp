#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {

    if (s[0] >= 'a' && s[0] <= 'z') s[0] -= 32;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (s[i + 1] >= 'a' && s[i + 1] <= 'z') {
                s[i + 1] -= 32;
                i++;
            }
        }
        if (s[i-1] != ' ' && s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    } 
  
    return s;
}

int main() {
    solution("3people unFollowed me");
}
