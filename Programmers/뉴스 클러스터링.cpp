#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define OFFSET 65536
using namespace std;

map<string,int> str1Set;
map<string,int> str2Set;
vector<string> total;

void subStr(string str, map<string,int>& strSet) {
    for (int i = 0; i < str.size()-1; i++) {
        if (!isalpha(str[i])) continue;
        if (!isalpha(str[i+1])) continue;

        string tmp;
        tmp = str.substr(i, 2);
        if (!str1Set[tmp]&& !str2Set[tmp]) total.push_back(tmp);
        strSet[tmp]++;
    }
}

void make_Set(string &str1, string &str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    subStr(str1, str1Set);
    subStr(str2, str2Set);
}

int find_Jakad() {
    if (total.size() == 0) return OFFSET;
    int intersection = 0, union_ = 0;
    for (int i = 0; i < total.size(); i++) {
        string str = total[i];
        intersection += min(str1Set[str], str2Set[str]);
        union_ += max(str1Set[str], str2Set[str]);
    }

    double jakad = (double) intersection / union_;
    return (int)(jakad * OFFSET);
}

int solution(string str1, string str2) {
    make_Set(str1, str2);
    return find_Jakad();
}

