#include <iostream>
#include <vector>

using namespace std;

int N, R;
bool alive[10002];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N >> R;
	int num; 
	for (int i = 0; i < R; i++) {
		cin >> num;
		alive[num] = true;
	}
}

void solution() {
	if (N == R) {
		cout << "*";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (alive[i]) continue;
		cout << i << " ";
	}
}

int main() {
	init();
	input();
	solution();
}
