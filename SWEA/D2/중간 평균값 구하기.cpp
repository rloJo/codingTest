#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, num;
  int sum;
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
    vector<int> ans;
		sum = 0;
		for(int i=0;i<10;i++){
         	cin >> num;
          ans.push_back(num);
        }
		sort(ans.begin(),ans.end());
    for(int i=1;i<ans.size()-1;i++)
        sum += ans[i];
		cout << "#" << test_case << " " << round(sum/8.0) << "\n";
	}
	return 0;
}
