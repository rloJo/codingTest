#include <string>
#include <vector>

using namespace std;

int answer = 100;
bool vis[52] = { false };

bool check_alpha(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.size();i++) {
        if (a[i] != b[i]) cnt++;
    }
    return cnt ==1;
}

void DFS(string begin, string target, int cnt, vector<string>& words) {

    if (begin == target) {
        answer = min(answer, cnt);
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        if (vis[i]) continue;
        if (!check_alpha(begin, words[i])) continue;
        vis[i] = true;
        DFS(words[i], target, cnt + 1, words);
        vis[i] = false;      
    }
}


int solution(string begin, string target, vector<string> words) {
 
    DFS(begin, target, 0, words);
    if (answer >= 100) return 0;
    return answer;
}
