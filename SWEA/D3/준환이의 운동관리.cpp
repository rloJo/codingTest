#include<iostream>

using namespace std;

int exercise(int L, int U, int X)
{
	if (X >= L && X <= U) // X값이 L, U 사이에 있을 때 -> 적당히 운동했을 때
		return 0;
	else if (X >= U) // X값이 U보다 클 때 -> 운동량을 오버했을 때
		return -1;
	else
		return L - X; // 운동량이 적을 떄

}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int L, U, X; // 문제 L, U, X 정의

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> L >> U >> X;
		cout << "#" << test_case << " " << exercise(L, U, X) << "\n";
	}
	return 0;
}
