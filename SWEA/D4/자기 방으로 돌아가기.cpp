#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int test_case = 0;
vector<pair<int, int>> student;
int N;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	student = vector<pair<int, int>>(N);
	for (int i = 0; i < N; i++) {
		int st, ed; cin >> st >> ed;
		student[i] = { min(st,ed),max(st,ed) };
	}
}

void solution() {
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		input();
		vector<int> cnt(202, 0);
		for (int i = 0; i < student.size(); i++) {
			int st = student[i].first % 2 ? student[i].first / 2 : (student[i].first -1) / 2;
			int ed = student[i].second % 2 ? student[i].second / 2 : (student[i].second - 1) / 2;
			for (int k = st; k <= ed; k++) cnt[k]++;
		}
		sort(cnt.begin(), cnt.end(), greater<int>());
		cout << "#" << tc << " " << cnt[0] << "\n";
	}
}

int main() {
	init();
	solution();
	return 0;
}
