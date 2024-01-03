#include <iostream>
#include <algorithm>
/*
두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다. 
합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.
전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다. 
전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때,
남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하는 프로그램을 작성하시오.


첫째 줄에는 두 전봇대 사이의 전깃줄의 개수가 주어진다. 전깃줄의 개수는 100 이하의 자연수이다. 
둘째 줄부터 한 줄에 하나씩 전깃줄이 A전봇대와 연결되는 위치의 번호와 B전봇대와 연결되는 위치의 번호가 차례로 주어진다.
위치의 번호는 500 이하의 자연수이고, 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다.
*/

using namespace std;

int main() {
	int N, max = 0;
	cin >> N;
	pair<int,int>* A = new pair<int,int> [N];
	int* dp = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> A[i].first >> A[i].second;
		dp[i] = 1;
	}

	sort(A, A+N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[j].second < A[i].second)
			{
				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
			}
		}

		max = max > dp[i] ? max : dp[i];
	}

	cout << N - max << "\n"; 
	// 자르는 전깃줄을 구하기 때문에 전체 전깃줄 수 에서 최장 부분 수열 크기를 뺀다

	delete[] A;
	delete[] dp;

	//동적 프로그래밍
	return 0;
}
