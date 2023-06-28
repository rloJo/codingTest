#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		cout << "#" << test_case << " ";
		cout << N / 3 <<"\n";
		// 학생 수를 3만큼 나누면 최대 조 수가 나옴
		// 나머지는 나눠진 조로 알아서 들어감.
	}
	return 0;
}
