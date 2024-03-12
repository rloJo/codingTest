#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 안타 1 2루타 2 3루타 3 홈런 4 아웃 0
int N; // 이닝 수 
int result[52][10]; // [각이닝][타자 결과]
vector<int> lineup = { 1,2,3,4,5,6,7,8 }; //1번(인덱스 0번) 선수는 4번타자 고정
int max_score = 0; // 최대 득점 기록

void simulation() { // 각 이닝 시뮬레이션 함수
	vector<int> order = lineup;
	order.insert(order.begin() + 3, 0); //4번타지에 1번(인덱스 0번) 선수 추가
	int ining = 0; //이닝 진행수
	int score = 0, hitter = 0; // 점수, 타순
	while (ining < N) {
		int out = 0; // 아웃 카운트 
		bool runner[3] = { 0,0,0 }; // 각 루에 있는 주자  0->1루 1->2루 2->3루
		while (out < 3) // 아웃이 3이 넘어가면 이닝 종료
		{
			if (result[ining][order[hitter]] == 0) out++;
			else if (result[ining][order[hitter]] == 1)
			{
				if (runner[2]){ // 3루 주자 홈인
					score++; runner[2] = 0;
				}
				if (runner[1]) { // 2루 주자 3루로 진루
					runner[1] = 0; runner[2] = 1;
				}
				if (runner[0]) { // 1루 주자 2루로 진루
					runner[0] = 0; runner[1] = 1;
				}
				runner[0] = 1; //타자 1루
			}
			else if (result[ining][order[hitter]] == 2)
			{
				if (runner[2]) { //3루 주자 홈인
					score++; runner[2] = 0;
				}
				if (runner[1]) { //2루 주자 홈인
					score++; runner[1] = 0;
				}
				if (runner[0]) { //1루 주자 3루
					runner[0] = 0; runner[2] = 1;
				}
				runner[1] = 1; //타자는 2루
			}
			else if (result[ining][order[hitter]] == 3)
			{
				for (int i = 0; i < 3; i++) {
					if (runner[i]) score++; // 모든 주자 홈인
					runner[i] = 0;
				}			
				runner[2] = true; //타자 3루
			}
			else if (result[ining][order[hitter]] == 4)
			{
				for (int i = 0; i < 3; i++) {
					if (runner[i]) score++; // 주자 홈인
					runner[i] = 0;
				}
				score++; // 타자 홈인
			}
			hitter++;
			hitter %= 9;
		}
		ining++;
	}

	max_score = max(max_score, score);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 9; j++)
			cin >> result[i][j];

	do {
		simulation();
	} while (next_permutation(lineup.begin(), lineup.end()));
	// 순열(타순) 구하기

	cout << max_score << "\n";
	return 0;
}
