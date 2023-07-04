#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int dump;
	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<int>height(100);
		cin >> dump;
		for (int i = 0; i < 100; i++)
			cin >> height[i];
		sort(height.begin(), height.end());
		for (int i = 1; i <= dump; i++)
		{
			if (height[height.size() - 1] - height[0] <= 1)
				break;
			height[0] ++; height[height.size() - 1]--;
			sort(height.begin(), height.end());
		}		
		cout << "#" << test_case << " " << height[height.size() - 1] - height[0] << "\n";
	}
	return 0;
}

// 주어진 문제의 실행시간이 넉넉해서 풀리는 문제 
// 더 간단히 줄여볼 필요있음
