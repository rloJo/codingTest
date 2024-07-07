#include <string>
#include <vector>

using namespace std;
int cnt = -1;
int answer = 0;
string vowels = "AEIOU";
void DFS(string word, string target) {
    cnt++;
    if (word == target)
    {
        answer = cnt;
        return;
    }

    if (word.length() >= 5) return;

    for (int i = 0; i < vowels.length(); i++) {
        DFS(word + vowels[i],target);
    }
}

int solution(string word) {
    DFS("", word);
    return answer;
}
