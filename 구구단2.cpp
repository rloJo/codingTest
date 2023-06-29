#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int A, B;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> A >> B;
		cout << "#" << test_case << " ";
		(A >= 10 || B >= 10) ? cout << -1 : cout << A * B;
		cout << "\n";
	}
	return 0;
}
