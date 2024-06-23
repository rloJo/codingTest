#include <string>

#define MOD 1234567
#define MAX 100000
using namespace std;

int fibo[100002];

void make_fibo() {
    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2; i <= MAX; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= MOD;
    }
}

int solution(int n) {
    make_fibo();
    return fibo[n];
}
