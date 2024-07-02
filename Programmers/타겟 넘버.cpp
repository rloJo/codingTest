#include <vector>

using namespace std;

int answer = 0;

void DFS(vector<int>& numbers, int index, int sum, int target) {
    if (index == numbers.size()) {
        if (sum == target) answer++;
        return;
    }

    DFS(numbers, index+1, sum + numbers[index], target);
    DFS(numbers, index+1, sum + (numbers[index] * -1), target);
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, 0, 0, target);
    return answer;
}
