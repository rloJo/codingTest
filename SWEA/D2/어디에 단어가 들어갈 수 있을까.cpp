#include<iostream>
#include<vector>
using namespace std;

int check_map(vector<vector<int>>map, int N, int K)
{
	int ans = 0;
	int count = 0;

	//가로 검사 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0 && count == K)
			{
				ans++;
				count = 0;
			}
			else if (map[i][j] == 0)
				count = 0;
			else
				count++;
		}
		if (count == K)
			ans++;
		count = 0;
	}

	count = 0;

	//세로 검사
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[j][i] == 0 && count == K)
			{
				ans++;
				count = 0;
			}
			else if (map[j][i] == 0)
				count = 0;
			else
				count++;
		}
		if (count == K)
			ans++;
		count = 0;
	}

	return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T,N,K;
	int ans, num;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		vector<vector<int>> map(N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> num;
				map[i].push_back(num);
			}
		}

		ans = check_map(map, N, K);

		cout << "#" << test_case <<" " << ans << "\n";

	}
	return 0;
}
