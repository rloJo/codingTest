#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N;
	int max;
	int count;
	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		count = 0;
		cin >> N;
		vector<int> building(N);
		for (int i = 0; i < N; i++)
			cin >> building[i];
		for (int i = 2; i < N - 2; i++)
		{
			max = 0;
			if (building[i - 2] < building[i] && building[i + 2] < building[i] && building[i - 1] < building[i] && building[i + 1] < building[i]);
			else  continue;
			for (int j = -2; j <= 2; j++)
			{
				if (j != 0)
					max = max > building[i + j] ? max : building[i + j];
			}
			count += building[i] - max;
		}

		cout << "#" << test_case << " " << count << "\n";


	}
	return 0;
}
