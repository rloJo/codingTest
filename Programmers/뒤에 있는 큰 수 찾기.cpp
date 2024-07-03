#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(),-1);
    stack<int> stk;
    stk.push(numbers[numbers.size() - 1]);
    for (int i = numbers.size()-2 ; i >= 0; i--) {
        bool check = false;
        while (!stk.empty())
        {
            int top = stk.top();
            stk.pop();
            if (top > numbers[i]) {
                answer[i] = top;
                check = true;
                break;
            }
        }
        if (check) stk.push(answer[i]);
        stk.push(numbers[i]); 
    }
    return answer;
}
