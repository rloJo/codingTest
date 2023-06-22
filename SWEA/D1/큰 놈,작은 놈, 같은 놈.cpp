#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int A, B;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> A;
        cin >> B;
        if (A>B)
            cout << "#" << test_case << " " << ">" << "\n";
        else if (A<B)
             cout << "#" << test_case << " " << "<" << "\n";
        else
             cout << "#" << test_case << " " << "=" << "\n";
		
	}
	return 0;
}
