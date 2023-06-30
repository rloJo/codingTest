#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T,num;
	int ans;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int count[10] = { 0 };
		ans = 0;
		cin >> num;
		while (num)
		{
			count[num % 10] ++;
			num /= 10;
		}
		 
		for (int i = 0; i < 10; i++)
			ans = count[i] > 0 ? ans+1 : ans ;

		cout << "#" << test_case << " " << ans <<  "\n";
	}
	return 0;
}
