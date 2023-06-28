#include<iostream>
#include<vector>

using namespace std;

int count_person(vector<int> income, float avg) // 평균이하의 소득을 갖는 사람 수를 세는 함수 정의
{
	int count = 0;
	for (int i = 0; i < income.size(); i++)
		count += income[i] <= avg ? 1 : 0;

	return count;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int sum = 0; // 입력과 동시에 합을 구하기위한 변수 선언
		cin >> N;
		vector<int> income(N); // 소득을 입력받을 벡터 정의
		for (int i = 0; i < N; i++)
		{
			cin >> income[i];
			sum += income[i];
		}
		
		cout << "#" << test_case << " " << count_person(income, (float)sum/N) << "\n";
	}
	return 0;
}
