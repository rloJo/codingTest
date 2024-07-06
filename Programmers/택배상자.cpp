#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    stack<int> subCon;
    int answer = 0;
    int cur = 0;
    for (int i = 1; i <= order.size(); i++) {
        if (i != order[cur]) subCon.push(i);
        if (i == order[cur]) {
            cur++;
            answer++;
        }
        while (!subCon.empty() && subCon.top() == order[cur]) {
            subCon.pop();
            cur++;
            answer++;
        }
    }
    return answer;
}
