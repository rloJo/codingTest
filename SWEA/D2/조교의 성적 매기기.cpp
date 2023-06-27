#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	string total[10] = { "A+", "A0", "A-","B+","B0","B-","C+","C0", "C-", "D0" };
	int test_case;
	int T, N, K;
	int mid_e, final_e, assign;
	int index;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		index = 0;
		cin >> N >> K;
		vector<pair<double,pair<int, string>>> score(N);
		for (int i = 0; i < N; i++) {
			cin >> mid_e >> final_e >> assign;
			score[i].first = mid_e * 0.35 + final_e * 0.45 + assign * 0.2;
			score[i].second.first = i + 1;
		}
		sort(score.begin(),score.end(), greater<>());
		cout << "#" << test_case << " ";
		for (int i = 0; i < N; i++)
		{
			score[i].second.second = total[index];
			if ((i+1) % (N / 10) == 0)
			{
				index++;
			}
			if (score[i].second.first == K)
			{
				cout << score[i].second.second << "\n";
				break;
			}
		}
	}
	return 0;
}
