#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
  int score;
   pair<int,int> max;
  int test_num;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
    {
        int max_count[101] = {0};
        max.first = -1;
        max.second= 0;
        cin >> test_num;
        for(int i=0;i<1000; i++){
            cin >> score; 
            max_count[score]++;
        }
        
        for(int i=0;i<101;i++){
           if(max.first <= max_count[i])
           {
               max.first = max_count[i];
               max.second = i;
           }
        }        
        cout << "#" << test_num <<" "<< max.second << "\n";
	}
	return 0;
}
