#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    string T; 
	  cin>> T;
	
    for(int i=0;i<T.size();i++){
        
     cout << T[i] - 'A' + 1 << " " ;   
    }
	return 0;
}
