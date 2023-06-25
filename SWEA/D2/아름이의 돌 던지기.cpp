#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
  int N;
  int count;
  int min_pos;
  int pos;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        min_pos=10001;
        count =0; 
		    cin >> N;
        for(int i=0;i<N;i++)
        {
            cin >> pos;
            if(abs(pos)==min_pos)
                count ++;
            else if(abs(pos) < min_pos){
             	min_pos = abs(pos);
                count = 1;
            } else
                continue;
        }		
	}
	return 0;
}
