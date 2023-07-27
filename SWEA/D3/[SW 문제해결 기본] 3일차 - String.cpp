#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, ans;
	string text;
	string select;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		ans = 0;
		cin >> T >> select >> text;
		while (1)
		{
			if (text.find(select) == string::npos)
				break;
			else
			{
				ans++;
				text = text.substr(text.find(select) + select.size());
			}
		}

		cout << "#" << T << " " << ans << "\n";
	}
	return 0;
}
