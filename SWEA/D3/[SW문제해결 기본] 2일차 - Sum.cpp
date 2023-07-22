#include<iostream>
#include<vector>
#define max(a,b) (((a) > (b) ? (a) : (b)))

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, rsum = 0, csum = 0;
	int ans = 0;
	int num = 0;
	T = 10;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<vector<int>> arr(100);
		csum = 0;
		rsum = 0;
		ans = 0;
		cin >> num;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> num;
				arr[i].push_back(num);
			}
		}

		for (int i = 0; i < 100; i++)
		{
			csum = 0; rsum = 0;
			for (int j = 0; j < 100; j++)
			{
				rsum += arr[i][j];
				csum += arr[j][i];
			}
			ans = max(max(csum, rsum), ans);
		}
		rsum = 0;
		csum = 0;
		for (int i = 0; i < 100; i++)
		{
			rsum += arr[i][i];
			csum += arr[100 -1 - i][100 -1 - i];
		}
		ans = max(max(csum, rsum), ans);
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}
