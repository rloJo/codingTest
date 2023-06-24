#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
  int last_day[12] = { 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31 , 30 ,31};
  int test_case;
  int T;
  int M1, D1, M2, D2;
  int dday;
  cin>>T;
	
  for(test_case = 1; test_case <= T; ++test_case)
  {
  	dday = 0;
  	cin >> M1 >> D1 >> M2 >> D2; 
  	if(M1 == M2)
  		dday = D2 - D1 +1;
 	 else {
 		dday += last_day[M1-1] - D1 + 1;
  		for(int i=M1; i<M2-1;i++)
  			dday+= last_day[i];
  		dday += D2;
  	}
  	cout << "#" << test_case << " " << dday << "\n";
  }
  return 0;
}
