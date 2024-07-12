#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int cnt[11] = { 0 };
set<int> num;

void DFS(string n) 
{
    for (int i = 0; i <= 9; i++) {
        if (cnt[i] <= 0) continue;
        cnt[i]--;
        num.insert(stoi(n + to_string(i)));
        DFS(n + to_string(i));
        cnt[i]++;
    }
}

int solution(string numbers) {
    int answer = 0;
    for (char number : numbers)
        cnt[number - '0']++;
    DFS("");
    for (auto n : num) {
        bool check = true;
        if (n < 2) check = false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                check = false;
                break;
            }
        }
        if (check) answer++;
    }

    return answer;
}
