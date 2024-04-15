#include <iostream>

using namespace std;

string check(int a, int b, int c) {
	if (max(a, max(b, c)) >= a + b + c - max(a, max(b, c))) return "Invalid";
	if (a == b && b == c) return "Equilateral";
	if (a == b || b == c || c == a) return "Isosceles";
	return "Scalene";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a,b,c;

	while (1) {
		cin >> a >> b >> c;
		if (!a && !b && !c) break;
		cout << check(a, b, c) << "\n";
	}

}
