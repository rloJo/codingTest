#include<iostream>
#include<vector>

using namespace std;

pair<int, int> check_difficulty(vector<int> obstacle) // 난이도 파악 함수 정의
{
	pair<int, int> difficulties;
	difficulties.first = 0; difficulties.second = 0;
	for (int i = 0; i < obstacle.size() - 1; i++)
	{
		if (obstacle[i] < obstacle[i + 1])
		{
			difficulties.first = ((obstacle[i+1]-obstacle[i]) > difficulties.first) ? obstacle[i + 1] - obstacle[i] : difficulties.first;
		}
		else {
			difficulties.second = ((obstacle[i] - obstacle[i+1]) > difficulties.second) ? obstacle[i] - obstacle[i+1] : difficulties.second;
		}
	}

	return difficulties;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		vector<int> obstacle(N);
		for (int i = 0; i < N; i++)
			cin >> obstacle[i];

		cout << "#" << test_case << " " << check_difficulty(obstacle).first << " " << check_difficulty(obstacle).second << "\n";
	}
	return 0;
}
