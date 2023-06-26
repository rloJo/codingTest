#include<iostream>
#include<vector>
using namespace std;

int check_max(vector<int> A, vector<int> B, int N, int M) {
	int max = -1000000000;
	int sum = 0;
	if (N > M)
	{
		for (int j = 0; j < N-M+1; j++)
		{
			for (int i = 0; i < M; i++)
			{
				sum += A[i+j] * B[i];
			}
			if (sum > max)
				max = sum;
			sum = 0;
		}
	}

	else {
		for (int j = 0; j < M - N + 1; j++)
		{
			for (int i = 0; i < N; i++)
			{
				sum += A[i] * B[i + j];
			}
			if (sum > max)
				max = sum;
			sum = 0;
		}
	}

	return max;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N, M;
	int max;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		vector<int> A(N);
		vector<int> B(M);
		for(int i = 0; i < N; i++)
			cin >> A[i];
		for(int i = 0; i < M; i++)
			cin >> B[i];

		max = check_max(A,B,N,M);
		cout << "#" << test_case << " " << max << "\n";
	}
	return 0;
}
