#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, D;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> D;
		vector<int> price(D);
		for (int i = 0; i < D; i++)
			cin >> price[i];
		int budget = price[D - 1];
		long long max = 0;

		for(int i = D-1; i >= 0; i--)
		{
			if (budget >= price[i])
				max = max + (budget - price[i]);
			else
				budget = price[i];
		}
		
		cout << "#" << test_case << " " << max << "\n";

	}
	return 0;
}
