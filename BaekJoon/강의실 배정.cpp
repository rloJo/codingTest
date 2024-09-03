#include <iostream>
#include <queue>
#include <algorithm>

#define ed second
#define st first
using namespace std;

int N;
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
vector<pair<int, int>> lecture;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	lecture = vector<pair<int, int>>(N);
	for (int i = 0; i < N; i++) cin >> lecture[i].st >> lecture[i].ed;
	sort(lecture.begin(), lecture.end());
}

void solution() {
	int answer = 0;
	for (int i = 0; i < N; i++) {
		while (!Q.empty() && Q.top().first <= lecture[i].st) Q.pop();
		Q.push({lecture[i].ed, lecture[i].st});
		answer = max(answer,(int)Q.size());
	}
	cout << answer;
}

int main() {
	init();
	input();
	solution();
}
