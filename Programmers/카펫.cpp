#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> find_size(int brown, int yellow) {
    vector<int> ans;
    int width = 0;
    int height = 0;

    for (int i = 1; i * i <= yellow; i++) {
        if (yellow % i == 0) {
            width = yellow / i;
            height = i;
            if ((width + 2) * 2 + height * 2 == brown) break;
        }
    }

    ans.push_back(width+2);
    ans.push_back(height+2);
    return ans;
}

vector<int> solution(int brown, int yellow) {
    return find_size(brown, yellow);
}

int main() {
    solution(10, 2);
}
