#include<iostream>

using namespace std;

int time_check(int now, int pass) // pass시간이  지난 후 시간 계산 함수
{
	int after = now + pass;
	if (after >= 24)
		return after - 24;
	else
		return after;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int now, pass; //현재 시간과 흐른 시간 정의
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> now >> pass;
		cout << "#" << test_case << " " << time_check(now, pass) << "\n";
	}
	return 0;
}
