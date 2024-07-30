#include <iostream>
#include <algorithm>

using namespace std;

int lines[3];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	for (int i = 0; i < 3;i++) {
		cin >> lines[i];
	}
}

bool isTriangle() {
	if (lines[0] < lines[1] + lines[2]) return true;
	return false;
}

void solution() {
	while (1) {
		input();
		if (!lines[0] && !lines[1] && !lines[2]) break;
		sort(lines, lines + 3, greater<>());
		if (!isTriangle()) {
			cout << "Invalid" << "\n";
			continue;
		}
		if (lines[0] == lines[1] && lines[1] == lines[2]) cout << "Equilateral" << "\n";
		else if (lines[1] == lines[2] || lines[0] == lines[1]) cout << "Isosceles" << "\n";
		else cout << "Scalene" << "\n";
	}
}

int main() {
	init();
	solution();
}
