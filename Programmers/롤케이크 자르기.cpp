#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> p1;
unordered_map<int, int> p2;

int solution(vector<int> topping) {
    int answer =0;
    p1[topping[0]]++;
    for (int i = 1; i < topping.size();i++) p2[topping[i]]++;

    for (int cur = 1; cur < topping.size() - 1;cur++) {
        if (p1.size() == p2.size()) answer++;
        p1[topping[cur]]++;
        p2[topping[cur]]--;
        if (p2[topping[cur]] <= 0) p2.erase(topping[cur]); 
    }

    return answer;
}
