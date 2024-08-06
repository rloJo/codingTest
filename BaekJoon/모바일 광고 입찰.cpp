#include <iostream>
#include <map>

using namespace std;

int N, K;
int A[100000];
int B[100000];
int bidCnt = 0;
int answer = 0;
map<int, int> price;


void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		if (A[i] - B[i] >= 0) bidCnt++;
		else price[B[i] - A[i]]++;
	}
}

void solution() {
	if (bidCnt >= K) {
		cout << answer << "\n";
		return;
	}

	for (auto iter= price.begin(); bidCnt < K;iter++) {
		bidCnt += iter->second;
		answer = iter->first;
	}
	cout << answer << "\n";
}

int main() {
	init();
	input();
	solution();
}
