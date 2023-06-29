#include<iostream>
#include<vector>
#include<string>

using namespace std;

int count_pelindrome(vector<string> word, int range) // 펠린드롬 세는 함수 정의
{
	int count = 0;
	bool flag = true;
	for (int i = 0; i < word.size(); i++) //행 시작  총 8번 반복
	{
		// 가로 검사
		for (int j = 0; j < word[i].size() - range + 1; j++) { // 한 행당 word[i].size()- range + 1 만큼 반복 하는 규칙이 있다.
			flag = true;
			for (int k = 0; k < range / 2; k++) // range 길이의 단어 하나 당 range/2 만큼 검사가 필요함.
			{
				if (word[i][j+k] != word[i][range -1 -k +j]) // 문자열의 양쪽으로 검사
				{
					flag = false;
					break;
				}
			}
			if (flag)
				count++;
		}

		//세로 검사
		for (int j = 0; j < word[i].size() - range + 1; j++) { // 한 열당 word[i].size()- range + 1 만큼 반복 하는 규칙이 있다.
			flag = true;
			for (int k = 0; k < range / 2; k++)
			{
				if (word[j+k][i] != word[range - 1 - k + j][i])
				{
					flag = false;
					break;
				}
			}
			if (flag)
				count++;
		}
	}
	return count;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int range; // 길이변수 
	
	T = 1;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> range;
		vector<string> word(8); // 글자판 배열 
		for (int i = 0; i < 8; i++)
			cin >> word[i];

		cout << "#" << test_case << " " << count_pelindrome(word, range) << "\n";
	}
	return 0;
}
