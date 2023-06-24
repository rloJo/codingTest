#include<iostream>
#include<string>
 
using namespace std;
 
int main(int argc, char** argv)
{
    string str;
    int N;
    cin>>N;
     
    for(int i=1; i<=N; i++){
        int count =0; 
        str = to_string(i);
        for(int j=0;j<str.size();j++) {
            if(str[j] == '3' || str[j] =='6' || str[j] == '9')
                count ++;
        }
        if(count)
        {
            str = "";
            for(int i=0;i<count;i++)
                str.push_back('-');
        }
        cout << str << " " ;        
    }
    return 0;
}
