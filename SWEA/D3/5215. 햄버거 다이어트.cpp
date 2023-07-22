#include<iostream>
#include<vector>
#define max(a,b) (((a) > (b) ? (a) : (b)))

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N, L;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> L;
		vector<pair<int, int>> hambuger(N); //first는 맛 점수(val) , second는 칼로리(weight)
		vector<vector<int>>ans(N + 1, vector<int>(L + 1, 0)); // dp를 위한 ans 이차원 배열
		for (int i = 0; i < N; i++)
		{
			cin >> hambuger[i].first >> hambuger[i].second;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= L; j++) {
				int curweight = hambuger[i - 1].second;
				int curval = hambuger[i - 1].first;
				if (curweight <= j)
				{
					ans[i][j] = max((ans[i - 1][j - curweight] + curval), ans[i - 1][j]);
				}
				else {
					ans[i][j] = ans[i - 1][j];
				}
			}
		}

		cout << "#" << test_case << " " << ans[N][L] << "\n";

	}
	return 0;
}
