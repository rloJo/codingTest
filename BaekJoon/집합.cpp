#include <iostream>

using namespace std;

bool S[22];
int M, x;
string instruction;

void add() {
	cin >> x;
	S[x] = true;
}

void remove() {
	cin >> x;
	S[x] = false;
}

void check() {
	cin >> x;
	if (S[x]) cout << 1 << "\n";
	else cout << 0 << "\n";
}

void toggle() {
	cin >> x;
	S[x] = !S[x];
}

void all() {
	for (int i = 1; i <= 20; i++) S[i] = true;
}

void empty() {
	for (int i = 1; i <= 20; i++) S[i] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M;
	while (M--) {
		cin >> instruction;
		if (instruction == "add") add();
		else if (instruction == "remove") remove();
		else if (instruction == "check") check();
		else if (instruction == "toggle") toggle();
		else if (instruction == "all") all();
		else empty();
	}
}
