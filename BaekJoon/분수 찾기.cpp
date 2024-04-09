#include <iostream>

using namespace std;

int X;
int u, d;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> X;
	int i = 1;
	while (X - i > 0) {
		X -= i;
		i++;
	}
	if (i % 2 == 1)
		cout << i + 1 - X << "/" << X;
	else
		cout << X << "/" << i + 1 - X;
	return 0;
}
