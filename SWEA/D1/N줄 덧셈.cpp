#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int T;
	cin>>T;
  int sum =0;
	for(int i= 1; i <= T; ++i)
	{
		sum += i;
	}
    
  cout << sum;
	return 0;
}
