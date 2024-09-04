#include <iostream>
#include <vector>
#include <algorithm>
#define st second
#define ed first

using namespace std;

int N;
int mnd = 2000; 
int mxd = 0;
vector<pair<int,int>> flowers;


void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	flowers = vector<pair<int, int>>(N);
	for (int i = 0; i < N; i++) {
		int openMonth, openDay, closeMonth, closeDay;
		cin >> openMonth >> openDay >> closeMonth >> closeDay;
		flowers[i].st = openMonth * 100 + openDay;
		flowers[i].ed = closeMonth * 100 + closeDay;
		mxd = max(flowers[i].ed, mxd);
		mnd = min(flowers[i].st, mnd);
	}

	sort(flowers.begin(), flowers.end());
}

void solution() {
	if (mxd <= 1130 || mnd > 301) {
		cout << 0;
		return;
	}

	int answer = 0;
	int t = 301;
	while (t < 1201) {
		int nextT = t;
		for (int i = 0; i < N; i++) {
			if (flowers[i].st <= t && flowers[i].ed > nextT) nextT = flowers[i].ed;
		}

		if (nextT == t) {
			cout << 0;
			return;
		}
		answer++;
		t = nextT;
	}
	cout << answer;
}

int main() {
	init();
	input();
	solution();
}
