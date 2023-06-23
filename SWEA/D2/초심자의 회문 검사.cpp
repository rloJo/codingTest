#include<iostream>
#include<string>

using namespace std;

int check_palindrome(string str)
{
 	for(int i=0; i<str.size()/2;i++)
  {
     	if(str[i] != str[str.size()-1-i])
            return 0;
  }
  return 1;  
}


int main(int argc, char** argv)
{
  string tcase;
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> tcase;
    cout << "#" << test_case << " " << check_palindrome(tcase) << "\n" ;
	}
	return 0;
}
