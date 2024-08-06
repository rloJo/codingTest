#include <iostream>

using namespace std;

int T;
long long N, K;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> T;
}

void solution() {
	while (T--) {
		cin >> N >> K;
		while (N!=0 && K!=0) {
			N /= 2;
			K--;
		}
		cout << (N + 1) / 2 << "\n";
	}
}

int main() {
	init();
	input();
	solution();
}
