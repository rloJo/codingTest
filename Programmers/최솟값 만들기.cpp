#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int make_sum(vector<int>& A, vector<int>& B) {
    int msum = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), cmp);
    for (int i = 0; i < A.size();i++)
        msum += A[i] * B[i];
    return msum;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = make_sum(A,B);
    return answer;
}
