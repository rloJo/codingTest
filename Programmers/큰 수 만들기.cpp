#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 0;
    int cur = 0;

    //k개를 버리는것은 size - k개를 뽑는것과 같다
    for (int i = 0; i < number.size() - k; i++) {
        int mx = number[cur] - '0';
        int idx = cur;
        for (int j = cur; j <= i + k; j++) {
            if (mx < number[j] - '0') {
                mx = number[j] - '0';
                idx = j;

            }
        }
        cur = idx + 1;
        answer += to_string(mx);
    }

    return answer;
}

