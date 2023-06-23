#include<iostream>

using namespace std;

int calc_A(int P, int W)
{
 	return P * W;  
}

int calc_B(int Q, int R, int S, int W)
{
    if (W <= R)
    {
     	return Q;   
    }
    else {
     	return Q + (S * (W-R));   
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
  int P, Q, R, S, W;
  int A,B;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> P >> Q >> R >> S >> W;
		cout << "#" << test_case << " ";
    (calc_A(P, W) < calc_B(Q, R, S, W)) ? cout << calc_A(P,W) : cout << calc_B(Q,R,S,W);
    cout << "\n";
	}
	return 0;
}
