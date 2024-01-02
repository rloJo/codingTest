#include <iostream>

using namespace std;

int find(int dp[], int A[], int N)
{
	int max = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) // A배열의 해당 원소의 크기를 비교한다
				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1; 
			// 만약 A의 i번째 원소가 크면 dp의 i번쨰와 j번째의 크기 + 1(이제 i번째를 밟을 수 있으니까)
			// 비교하여 dp[i] 에 삽입 -> 해당 번호까지 제일 많이 밟는 경우를 저장하는 것
		}
		
		max = max > dp[i] ? max : dp[i];
	}

	return max;
}


int main(int argc, char** argv)
{
	int N = 0;
	cin >> N;
	int *A = new int[N];
	int *dp = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		dp[i] = 1; 
		//동적 프로그래밍을 위한 dp 배열 변수 추가 
		// 자신만을 밟고 가는 경우를 추가해 준다는 의미 
	}

	cout << find(dp, A, N) << "\n";

	delete[]A;
	delete[]dp;
	return 0;
}

/*
 dp를 이용하는 문제
 dp배열을 초기화를 하고
 어느 경우에 해당 dp 배열이 증가하는지 알아내는 문제
*/
