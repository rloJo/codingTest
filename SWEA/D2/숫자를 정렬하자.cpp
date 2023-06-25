#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int N;
    int num;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> ans;
        cin >> N;
        for(int i=0;i<N;i++){
            cin >> num;
            ans.push_back(num);
        }
       sort(ans.begin(),ans.end());
        cout << "#" << test_case << " ";
        for(int i=0;i<N;i++)
            cout << ans[i] << " " ;
        cout << endl;
	}
	return 0;
}
