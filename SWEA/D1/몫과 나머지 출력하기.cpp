#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int a,b;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> a >> b;
        cout << "#" << test_case << " " << a/b << " " << a%b << "\n" ;
	}
	return 0;
}
