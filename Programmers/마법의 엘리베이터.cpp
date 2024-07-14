#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while (storey > 0) {
        int mod = storey % 10; 
        if (mod > 5 ) {
            answer += 10 - mod;
            storey += 10;
        }
        else if (mod < 5)
            answer += mod;
        else {
            if ((storey%100) / 10 + 1 > 5) {
                answer += 10 - mod;
                storey += 10;
            }
            else   answer += mod;
        }

        storey /= 10;
    }
    return answer; 
}
