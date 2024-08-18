#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000000000
using namespace std;

int N;
vector<int> hills;
int cost = MAX;
int mx = 0;
int mn = MAX;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int height;
		cin >> height;
		hills.push_back(height);
		mx = max(mx, height);
		mn = min(mn, height);
	}
}

void solution() {
	for (int i = mn; i <= mx-17; i++) {
		int costToPay =0;
		for (int j = 0; j < N; j++) {
			if (hills[j] < i) costToPay += (i - hills[j]) * (i - hills[j]);
			if (hills[j] > (i + 17)) costToPay += (hills[j] - (i + 17)) * (hills[j] - (i + 17));
		}
		cost = min(costToPay, cost);
	}
	cout << cost << "\n";
}

int main() {
	init();
	input();
	solution();
}
