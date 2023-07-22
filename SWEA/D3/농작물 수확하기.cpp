#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T,N;
	int ans = 0;
	int mid = 0;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = 0;
		cin >> N;
		mid = N / 2;
		vector<vector<int>> farm(N, vector<int>(N, 0));
		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j < N; j++) {
				scanf("%1d", &farm[i][j]);
				ans += (mid == i) ? farm[i][j] : 0;
			}
		}

		for (int i = 0; i < N/2; i++)
		{
			for (int j = 0; j < N - (i + 1) * 2; j++) {
				ans += farm[mid+i+1][i+1+j];
				ans += farm[mid-i-1][i+1+j];
			}
		}

		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}
