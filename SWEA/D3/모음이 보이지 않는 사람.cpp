#include<iostream>
#include<string>

using namespace std;

string word_check(string word) // 자음 단어만 인식하는 함수 정의
{
	string temp ="";
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u')
			temp.push_back(word[i]);
	}
	return temp;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	string word; //단어 입력받을  변수 정의
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> word;
		cout << "#" << test_case << " " << word_check(word) <<"\n";
	}
	return 0;
}
