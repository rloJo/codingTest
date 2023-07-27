#include<iostream>
#include<vector>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	int max;
	int N, M;
	
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		max = 0;
		cin >> N >> M;
		vector<int> weight(N);
		for (int i = 0; i < N; i++)
			cin >> weight[i];
		for (int i = 0; i < N-1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (weight[i] + weight[j] <= M)
				{
					max = (weight[i] + weight[j]) > max ? (weight[i] + weight[j]) : max;
				}
			}
		}
		if(max!=0)
			cout << "#" << test_case << " " << max << "\n";
		else
			cout << "#" << test_case << " " << -1 << "\n";
	}
	return 0;
}
