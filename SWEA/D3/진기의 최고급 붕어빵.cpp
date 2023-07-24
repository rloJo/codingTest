#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	bool flag = true;
	int N, M, K;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int index = 0;
		flag = true;
		cin >> N >> M >> K;
		vector<int> client(N);
		for (int i = 0; i < N; i++)
			cin >> client[i];
		sort(client.begin(), client.end());
		for (int i = 0; i < N; i++)
		{
			if ((K * (client[i] / M) < i + 1)) {
				flag = false;
				break;
			}
		}
		flag == true ? cout << "#" << test_case << " " << "Possible" << "\n" : cout << "#" << test_case << " " << "Impossible" << "\n";
	}
	return 0;
}
