#include<iostream>
#include<string>
using namespace std;

int check_bit(string bit) { //문제의 조건대로 비트를 체크 하는 함수 정의
	string tmp = "";
	int ans = 0; //정답 변수
	for (int i = 0; i < bit.size(); i++) // tmp를 0으로 초기화
		tmp.push_back('0');

	for (int i = 0; i < bit.size(); i++)
	{
		if (tmp[i] != bit[i]) // tmp가 원하는 bit 값이랑 다르다면
		{
			ans++;
			for (int j = i; j < bit.size(); j++) { //해당 범위부터 끝까지 해당 문자로 변경
				tmp[j] = bit[i];
			}
		}
	}
	return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	string bit;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> bit;
		cout << "#" << test_case << " " << check_bit(bit) << "\n";
	}
	return 0;
}
