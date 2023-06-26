#include<iostream>
#include<vector>
using namespace std;

int max_fly(vector<vector<int>>fly, int N, int M)
{
	int max = 0;
	int sum = 0;
	for (int i = 0; i < N - M + 1; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			for (int ii = i; ii < M + i; ii++) {
				for (int jj = j; jj < M+j; jj++) {
					sum += fly[ii][jj];
				}
			}
			max = max < sum ? sum : max;
			sum = 0;
		}
	}

	return max;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N, M;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int num;
		cin >> N >> M;
		vector<vector<int>> fly(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> num;
				fly[i].push_back(num);
			}
		}

		cout << "#" << test_case << " " << max_fly(fly, N, M) << "\n";
	}
	return 0;
}

//4중 for문은 너무 하다 줄이는 법은 없을까?
