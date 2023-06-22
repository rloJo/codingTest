#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int N =0;
    int sum = 0;
    cin >> N;
    while(N!=0){
        sum += N%10;
        N /= 10;
    }
    cout << sum;
	return 0;
}
