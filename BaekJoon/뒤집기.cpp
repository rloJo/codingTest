#include <iostream>

using namespace std;

int make1 = 0;
int make0 = 0;
string S;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> S;
}

void solution() {
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] != S[i + 1]) {
			if (S[i] == '0') make0++;
			else make1++;
		}
	}
	cout << min(make0, make1);
}

int main() {
	init();
	input();
	solution();
}
