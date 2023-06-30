#include<iostream>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{

		cin >> N;
		cout << "#" << test_case << " " << N * N << "\n";
	}
	return 0;
}
