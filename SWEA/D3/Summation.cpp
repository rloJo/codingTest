#include<iostream>
#include<vector>

using namespace std;

pair <int, int> ans(vector<int> arr)
{
	pair<int, int> answer;
	answer.first = -1;
	answer.second = 90000000;
	for (int i = 0; i < arr.size(); i++)
	{
		int sum = 0;
		while (arr[i])
		{
			sum += arr[i] % 10;
			arr[i] /= 10;
		}
		if (sum > answer.first)
			answer.first = sum;
		if (sum < answer.second)
			answer.second = sum;
	}

	return answer;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<int>arr(10);
		for (int i = 0; i < 10; i++)
			cin >> arr[i];
		cout << "#" << test_case << " " << ans(arr).first << " "<< ans(arr).second << "\n";
		
	}
	return 0;
}
