#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long number : numbers) {
        if (number % 2 == 0) answer.push_back(number + 1);
        else {
            long long bit = 1;
            while (1){
                if ((number & bit) == 0) break;
                bit *= 2;
            }
            bit /= 2;
            answer.push_back(number + bit);
        }
    }
    return answer;
}
