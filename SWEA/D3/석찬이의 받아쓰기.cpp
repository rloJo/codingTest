#include<iostream>
#include<string>

using namespace std;

int count(string Q, string A)
{
	int ans = 0;
	for (int i = 0; i < Q.size(); i++)
	{
		ans = Q[i] == A[i] ? ans+1 : ans;
	}

	return ans;
}



int main(int argc, char** argv)
{
	int test_case;
	int T, N;
	string Q, A;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{

		cin >> N;
		cin >> Q >> A;
		cout << "#" << test_case << " " << count(Q,A) << "\n";
	}
	return 0;
}
