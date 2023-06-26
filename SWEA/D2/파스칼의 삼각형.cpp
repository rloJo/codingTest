#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		vector<vector<int>> triangle(N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				triangle[i].push_back(0);
			}
		}

		for (int i = 0; i < N; i++)
			triangle[i][0] = 1;
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < N; j++) {
				triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
			}
		}

		cout << "#" << test_case << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (triangle[i][j] != 0)
					cout << triangle[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
