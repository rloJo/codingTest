#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
  int distance;
  int c_count;
  int t_speed;
  int speed;
  int type;
    
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> c_count ;
        t_speed = 0;
        distance = 0;
        for(int i=0;i<c_count;i++){
        	cin >> type;
            switch(type)
            {
                case 0:  
                    distance += t_speed;
                    break;
                case 1: cin >> speed;
                        t_speed += speed;
                        distance += t_speed;
                    break;
                case 2: cin >> speed;
                        t_speed = ((t_speed - speed) <= 0 ) ? 0 : (t_speed - speed);
                        distance += t_speed;
                    break;
                default:
                    break;
            }
        }
		cout << "#" << test_case << " " << distance << "\n";
	}
	return 0;
}
