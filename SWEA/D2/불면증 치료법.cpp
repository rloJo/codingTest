#include<iostream>

using namespace std;

bool check_num(int* arr){
    for(int i=0;i<10;i++){
        if(arr[i] ==0)
            return false;     
    }
    return true;  
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int N;
    int Temp;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int count = 0;
		    cin >> N ;
        Temp = N;     
        while(!check_num(arr)){
            count++;
            N = Temp * count;
            while(N){
                ++arr[N%10];
                N /=10;
            }
        }
		    cout << "#" << test_case << " " << count * Temp << "\n" ;
	}
	return 0;
}
