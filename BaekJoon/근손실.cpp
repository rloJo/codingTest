#include <iostream>
#include <vector>
#include <algorithm>
#define Weight 500

using namespace std;

vector<int> v;
int weight = 500;
int N, K;
int A[9];
int answer;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		v.push_back(i);
	}
}

void solution() {
	do {
		weight = 500;
		bool flag = true;
		for (int i = 0; i < v.size(); i++) {
			weight -= K;
			weight += A[v[i]];
			if (weight < Weight) {
				flag = false;
				break;
			}
		}

		if (flag) answer++;

	} while (next_permutation(v.begin(), v.end()));

	cout << answer << "\n";
}

int main() {
	init();
	input();
	solution();
}
