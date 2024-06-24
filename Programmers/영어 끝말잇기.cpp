#include <string>
#include <vector>
#include <set>

using namespace std;
set<string> spokenWords;

bool check_rule(string lastword, string nowword) {
    return lastword[lastword.size() - 1] == nowword[0];
}

bool check_duplicate(string word) {
    return spokenWords.insert(word).second;
}

vector<int> solution(int n, vector<string> words) {
    string lastWord = words[0];
    spokenWords.insert(words[0]);
    for (int i = 1; i < words.size();i++) {
        if (check_rule(lastWord, words[i]) && check_duplicate(words[i])) {
            lastWord = words[i];
            continue;
        }
        return { i % n + 1,i / n + 1 };

    }
    return { 0,0 };
}
