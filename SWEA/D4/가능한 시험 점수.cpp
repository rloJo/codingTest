#include <iostream>
#include <vector>
using namespace std;

int test_case;
int N;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> test_case;
}

void solution() {
	for (int tc = 1; tc <= test_case; tc++) {
		vector<bool> outcome(10001, false);
		vector<int> score;
		cin >> N;
		score.push_back(0);
		outcome[0] = true;
		for (int i = 0; i < N; i++) {
			int point; cin >> point;
			int vSize = score.size();
			for (int i = 0; i < vSize; i++) {
				if (outcome[score[i] + point]) continue;
				score.push_back(score[i] + point);
				outcome[score[i] + point] = true;
			}
		}
		cout << "#" << tc << " " << score.size() << "\n";
	}
}

int main() {
	init();
	input();
	solution();
	return 0;
}
