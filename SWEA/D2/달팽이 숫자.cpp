#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N;
	int k = 1, dir = 1, num;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int arr[11][11] = { 0, };
		int row = 0, col = -1;
		int k = 1, dir = 1, num;
		cin >> N;
		num = N;
		while (N > 0)
		{
			for (int i = 0; i < N; i++)
			{
				col += dir;
				arr[row][col] = k;
				k++;
			}
			N--;
			for (int j = 0; j < N; j++)
			{
				row += dir;
				arr[row][col] = k;
				k++;
			}
			dir *= -1;
		}

		cout << "#" << test_case << "\n";

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";

		}
	}
	return 0;
}

//생각하기 까다로웠다 다시 한번 보자
