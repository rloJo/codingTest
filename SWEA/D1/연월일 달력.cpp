#include<iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv)
{
    bool flag = true ;
    int last_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int test_case;
    int T;
    int date;
    int Y,M,D;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
    	flag = true;
   	cin >> date;
    	D = date%100;  
    	date/=100;
   	M = date%100;
    	date /= 100;
    	Y = date;

    	if(M<1 || M >12)
        	flag = false;
    	else if(last_day[M-1] < D || D < 1)
        	flag = false;
    	cout << "#" << test_case << " " ;
    	if(flag)
        	cout << setw(4) << setfill('0') <<Y << "/" << setw(2) << setfill('0') <<M << "/" << setw(2) << setfill('0') << D << "\n";
    	else 
        	cout << "-1" << "\n";
    }
    return 0;
}
