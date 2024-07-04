#include <queue>
#include <vector>
using namespace std;

priority_queue<int,vector<int>,greater<int>> food;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for (int scov : scoville)
        food.push(scov);

    while (food.top() < K ) {
        if (food.size() < 2) break;
        int firstNonSpicyfood = food.top();  food.pop();
        int secondNonSpicyfood = food.top(); food.pop();
        int newSpicyFood = firstNonSpicyfood + secondNonSpicyfood * 2;
        food.push(newSpicyFood);
        answer++;
    }

    if (food.top() < K) return -1;
    else return answer;
}
