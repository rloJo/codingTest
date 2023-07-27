#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N, P;
	cin >> T;


	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		vector<int> A(N), B(N);
		for (int i = 0; i < N; i++)
			cin >> A[i] >> B[i];
		cin >> P;
		vector<int> C(P);
		vector<int> ans(P, 0);
		for(int i = 0; i < P; i++)
			cin >> C[i];

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < P; j++)
			{
				if (A[i] <= C[j] && B[i] >= C[j])
					ans[j]+=1;
			}
		}

		cout << "#" << test_case << " ";
		for (int i = 0; i < P; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}
