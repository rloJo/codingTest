#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s) {
        answer.push_back(-1);
        return answer;
    }

    int mod = s % n;

    answer.assign(n, s/n);

    for (int i = answer.size() - 1; i >= 0 && mod > 0; i--) {
        answer[i]++;
        mod--;
    }

    return answer;
}
