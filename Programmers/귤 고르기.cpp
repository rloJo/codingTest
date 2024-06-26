#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> cnt;
map<int, int> t_cnt;
void count_tangerines(vector<int>& tanger) {
    for (int i = 0; i < tanger.size(); i++)
        t_cnt[tanger[i]]++;

    for (auto iter = t_cnt.begin(); iter != t_cnt.end(); iter++) {
        cnt.push_back(iter->second);
    }

    sort(cnt.begin(), cnt.end(), greater<int>());
}

int find_way(int k) {
    int answer = 0;
    for (int i = 0; k > 0; i++) {
        k -= cnt[i];
        answer++;
    }
    return answer;
}

int solution(int k, vector<int> tangerine) {
    count_tangerines(tangerine);
    return find_way(k);
}
