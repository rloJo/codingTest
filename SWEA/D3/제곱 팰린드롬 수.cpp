#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> ans;

void square_palindrome()
{
	string origin = "";
	string sqrt = "";
	string tmp = "";
	for (int i = 1; i <= 31; i++)
	{
		origin = to_string(i);
		tmp = origin;
		reverse(tmp.begin(), tmp.end());
		if (origin != tmp) continue;
		sqrt = to_string(int(pow(i, 2)));
		tmp = sqrt;
		reverse(tmp.begin(), tmp.end());
		if (tmp == sqrt)
			ans.push_back(stoi(sqrt));
	}
	
}

int main(int argc, char** argv)
{
	int test_case;
	int T, A, B;
	int count = 0;
	cin >> T;
	square_palindrome();
	for (test_case = 1; test_case <= T; ++test_case)
	{
		count = 0;
		cin >> A >> B;
		for (int i = 0; i < ans.size(); i++)
		{
			if (A <= ans[i] && ans[i] <= B) count++;
		}
		cout << "#" << test_case << " " << count << "\n";
	}
	return 0;
}
