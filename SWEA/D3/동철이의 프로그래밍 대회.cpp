#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int score;
	int max, count = 0;
	int N, M;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		max = 0;
		count = 0;
		cin >> N >> M;
		vector<int> ans(N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> score;
				ans[i] += (score == 1)  ? 1 : 0;
			}

			if (max < ans[i])
			{
				max = ans[i];
				count = 1;
			}
			else if (max == ans[i])
				count++;
		}
		cout << "#" << test_case << " " << count  << " " << max << "\n";

	}
	return 0;
}
