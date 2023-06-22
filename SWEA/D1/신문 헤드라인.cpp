#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	string T;
	
	cin>>T;
  for(int i = 0;i<T.size();i++){
    T[i] = toupper(T[i]);
  }
  cout << T;
	return 0;
}
