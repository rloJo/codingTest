#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
  int num;
  int size = 10;
  int max = 0;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		for(int i=0;i<size ;i++){
            cin >> num;
            max = num > max ? num : max;
    }
    cout << "#" << test_case << " " << max << "\n";
    max = 0;
	}
	return 0;
}
