#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int num;
	
	cin>>T;
	vector<int> ans ;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> num;
		ans.push_back(num);
	}
    sort(ans.begin(), ans.end());
    cout << ans[T/2] << "\n";
    
	return 0;
}
