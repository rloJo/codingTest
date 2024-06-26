#include <string>
#include <vector>

using namespace std;

vector<int> make_array(int n, long long left, long long right) {
    vector<int> ans;
    for (long long i = left; i <= right; i++) {
        ans.push_back(max(i % n +1,  i / n+1 ));
    }
    return ans;
}

vector<int> solution(int n, long long left, long long right) {
    return make_array(n,left,right);
}

