#include <string>
#include <vector>

using namespace std;

int binary_count(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n % 2) cnt++;
        n /= 2;
    }

    return cnt;
}

int solution(int n) {
    int n_cnt = binary_count(n);
    while (1) {
        n++;
        if (n_cnt == binary_count(n)) return n;
    }
}
