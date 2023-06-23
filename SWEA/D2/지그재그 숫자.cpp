#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
  int N;
  int sum=0;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
    for(int i=1; i<=N;i++){
        sum += (i%2!=0) ? i : -1 * i ;
    }
    cout << "#" << test_case << " " << sum << "\n" ;
    sum = 0 ;
	}
	return 0;
}
