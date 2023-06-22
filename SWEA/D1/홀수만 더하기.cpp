#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int num; 
	int sum = 0;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        for(int i=0;i<10;i++){
        	cin >> num;
          	if(num%2!=0)
                sum+=num;
        }
		cout << "#" << test_case << " " <<  sum << "\n";
		sum = 0;
	}
	return 0;
}
