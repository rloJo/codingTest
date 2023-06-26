#include<iostream>
#include<vector>

using namespace std;

int check_sudoku(vector<vector<int>> puzzle)
{
	int test[4] = { 0,3,6,9 };
	//가로 검사 
	for (int i = 0; i < 9; i++) {
		int count[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			count[puzzle[i][j] - 1]++;
			if (count[puzzle[i][j]-1] > 1)
				return 0;
		}
	}

	// 세로 검사
	for (int i = 0; i < 9; i++) {
		int count[9] = { 0 };
		for (int j = 0; j < 9; j++) {
			count[puzzle[j][i] - 1]++;
			if (count[puzzle[j][i]-1] > 1)
				return 0;
		}
	}

	//격자 검사
	for (int i = 0; i < 9; i++) {
		int count[9] = { 0 };
		for (int j = i / 3 * 3 ; j < i /3 * 3 + 3 ;j++) {
			for (int k = test[i%3] ; k < test[i%3+1] ; k++) {
				count[puzzle[j][k] - 1]++;
				if (count[puzzle[j][k]-1] > 1)
					return 0;
			}
		}
	}

	return 1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int num;
		vector<vector<int>>puzzle(9);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> num;
				puzzle[i].push_back(num);
			}
		}
		cout << "#" << test_case << " " << check_sudoku(puzzle) << "\n";
	}
	return 0;
}
