#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	bool flag = false;
	int T,N;
	int temp = 0;
	int max = -1;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		max = -1;
		cin >> N;
		vector<int>arr(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		for (int i = N-1; i >= 1; i--)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				flag = false;
				temp  = arr[i] * arr[j];
				while (temp)
				{
					if (temp % 10 >= ((temp % 100)/10))
					{
						flag = true;
						temp /= 10;
					}
					else
					{
						flag = false;
						break;
					}
				}
				if (flag) {
					max = max > (arr[i] * arr[j]) ? max : arr[i] * arr[j];
				}
			}
		}
		cout << "#" << test_case << " " << max << "\n";
	}
	return 0;
}
