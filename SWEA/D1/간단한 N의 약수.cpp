#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int N = 0;
  cin >> N;
  for(int i=1;i<=N;i++){
    N%i==0 ? cout<< i << " " : cout << "";        
  }
	return 0;
}
