#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>;

using namespace std;

vector<int> num;

void split(string input, char delimeter) {
    istringstream iss(input);
    string buffer;
    while (getline(iss, buffer, delimeter)) {
        num.push_back(stoi(buffer));
    }
}

string find_min_max() {
    int mx = num[0];
    int mn = num[0];
    for (auto n : num) {
        mx = mx < n ? n : mx;
        mn = mn > n ? n : mn;
    }
    string result = to_string(mn) + " " + to_string(mx);
    return result;
}

string solution(string s) {
    split(s, ' ');
    return find_min_max();
}

