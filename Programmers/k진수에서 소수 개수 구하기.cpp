#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

bool isPrime(long long num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

string formation(int n, int k) {
    if (k == 10) return to_string(n);
    string fm = "";
    while (n > 0) {
        fm += n % k + '0';
        n /= k;
    }
    reverse(fm.begin(),fm.end());
    return fm;
}

vector<string> split(string str, char delimeter) {
    istringstream iss(str);
    string buffer;
    vector<string> result;

    while (getline(iss, buffer, delimeter)) {
        if (!buffer.compare("")) continue;
        result.push_back(buffer);
    }

    return result;
}

int solution(int n, int k) {
    vector<string> f;
    int answer = 0;
    string fm = formation(n, k);
    f = split(fm, '0');
    for (string c : f) {
        if (isPrime(stoll(c))) {
            answer++;
        }
    }
    return answer;
}
