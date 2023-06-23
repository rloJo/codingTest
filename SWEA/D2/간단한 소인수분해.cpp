#include<iostream>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int arr[5] = {2,3,5,7,11};
    int out = 0;
    int T;
    cin>>T;
    int num;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> num;
        cout << "#" << test_case << " ";
        for(int i=0; i <5; i++){
         while(num%arr[i]==0){
             num /= arr[i];
             out++;              
         }
            cout << out << " ";
            out = 0;
        }
        cout << "\n" ;        
    }
     
    return 0;
}
