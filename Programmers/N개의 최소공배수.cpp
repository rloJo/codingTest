#include <string>
#include <vector>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int r = 0;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a,int b) {
    return (a * b) / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}
