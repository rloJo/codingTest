#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int minCur = 0;
    int maxCur = people.size() - 1;
    int answer = 0;
    while (minCur <= maxCur) {
        if (people[minCur] + people[maxCur] <= limit) {
            answer++; 
            minCur++; 
            maxCur--;
        }
        else {
            maxCur--;
            answer++;
        }
    }
    return answer;
}
