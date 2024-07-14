#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while (n > 0) {
        int mod = n % 3;
        n /= 3;
        if(mod ==0){
            answer = "4" + answer;
            n--;
        }
        else if (mod == 1) {
            answer = "1" + answer;
        }
        else if (mod == 2) {
            answer = "2" + answer;
        }
    }
   
   return answer;
}
