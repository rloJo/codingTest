#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 1000001};
    int size = sequence.size();
    int st = 0; int ed = -1;
    int sum = 0;
    while (ed < size){
        if (sum == k && (ed - st) < (answer[1] - answer[0])) {
                answer[0] = st;
                answer[1] = ed;       
                sum -= sequence[st++];
        }
        else if (sum < k) sum += sequence[++ed];
        else sum -= sequence[st++];
    }

    return answer;
}

