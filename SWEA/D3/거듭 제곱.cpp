//문제조건 거듭제곱을 재귀함수로 작성해라
#include<iostream>

using namespace std;

int recursive_pow(int N, int M)
{
	if (M == 0)
		return 1;

	return N * recursive_pow(N,M-1);
}

int main(int argc, char** argv)
{
	int test_case;
	int num;
	int T,N,M;
	T=10;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> num >> N >> M;
		cout <<"#" << num << " " << recursive_pow(N, M) << "\n";

	}
	return 0;
}
