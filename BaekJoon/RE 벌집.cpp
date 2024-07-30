#include <iostream>

using namespace std;

int N;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
}

void solution() {
	int room = 1;
	int offset = 1;
	while (room < N) {
		room += 6 * offset++;
	}
	cout << offset << "\n";
}

int main() {
	init();
	input(); 
	solution();
}
