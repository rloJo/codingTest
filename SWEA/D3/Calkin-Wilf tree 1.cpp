#include<iostream>
#include<string>
using namespace std;

pair<int,int> Calkin_Wilf_tree(string str)
{
	pair<int, int> tree;
	int a = 1;
	int b = 1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'L')
			b += a;
		else
			a += b;
	}
	
	tree.first = a;
	tree.second = b;

	return tree;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;
		cout << "#" << test_case << " " << Calkin_Wilf_tree(str).first <<  " " << Calkin_Wilf_tree(str).second << "\n";
	}

	return 0;
}

//기약분수로 바꾸는 코드가 필요하다
//문제 조건이랑 답을 내는 로직이 다름
