#include <string>
#include <vector>

using namespace std;

int gcd(int a,int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int abase = arrayA[0];
    int bbase = arrayB[0];

    for (int i = 1; i < arrayA.size(); i++) {
        abase = gcd(abase, arrayA[i]);
        if (abase == 1) break;
    }

    for (int i = 1; i < arrayB.size(); i++) {
        bbase = gcd(bbase, arrayB[i]);
        if (bbase == 1) break;
    }

    if (abase != 1) {
        int i = 0;
        for (i = 0; i < arrayB.size(); i++) {
            if (arrayB[i] % abase == 0) break;
        }
        if (i == arrayB.size()) answer = abase;
    }

    if (bbase != 1) {
        int i = 0;
        for (i = 0; i < arrayA.size(); i++) {
            if (arrayA[i] % bbase == 0) break;
        }
        if (i == arrayA.size()) answer = max(bbase, answer);
    }

    return answer;
}
