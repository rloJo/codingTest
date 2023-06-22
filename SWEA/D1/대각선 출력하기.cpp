#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
   string ans = "+++++";
   int j=0; 
    for(int i=0; i<5;i++){   
        if(i==j)
            ans[i] =  '#';
        cout << ans << "\n";
        ans = "+++++";
        j++;
    }
	
	return 0;
}
