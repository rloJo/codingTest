#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int num;
	int boring = 0;
	int T, K;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> K;
		int p = pow(2, K);
		boring = 0;
		vector<int> ability;
		vector<int> temp;
		for (int i = 0; i <p; i++)
		{
			cin >> num;
			ability.push_back(num);
		}

		for (int i = 0; i < K; i++)
		{
			for (int j = 0; j < p; j+=2)
			{
				if (ability[j] >= ability[j + 1])
				{
					boring += ability[j] - ability[j + 1];
					temp.push_back(ability[j]);
				}

				else
				{
					boring += ability[j+1] - ability[j];
					temp.push_back(ability[j+1]);
				}
				ability.clear();
				ability = temp;
			}
			temp.clear();
			p /= 2;
		}

		cout << "#" << test_case << " " << boring << "\n";
	}
	return 0;
}
