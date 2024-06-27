#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> answer;

    for (int i = 1; i <= elements.size(); i++) { 
        for (int k = 0; k < elements.size(); k++) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                sum += elements[(k+j)%elements.size()];
            }
            answer.insert(sum);
        }
    }

    return answer.size();
}
