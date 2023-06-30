#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, num, trash;
	int last, algo;
	T=10;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> pw;
		algo = 1;
		cin >> trash;
		for (int i = 0; i < 8; i++)
		{
			cin >> num;
			pw.push_back(num);
		}
		
		while (1)
		{
			last = pw[0] - algo;
			last <=0 ? pw.push_back(0): pw.push_back(last);
			pw.erase(pw.begin());
			if (last <= 0)
				break;
			algo++;
			if (algo == 6)
				algo = 1;
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i < pw.size(); i++)
			cout << pw[i] << " ";
		cout << "\n";
	}
	return 0;
}
