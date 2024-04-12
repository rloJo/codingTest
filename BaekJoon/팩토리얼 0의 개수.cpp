#include <iostream>

using namespace std;

int N;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int a=0, b=0;
	for (int i = 1; i <= N; i++) {
		int tmp = i;
		while (1) {
			if (tmp % 2 != 0) break;
			tmp /= 2;
			a++;
		}
		tmp = i;
		while (1) {
			if (tmp % 5 != 0) break;
			tmp /= 5;
			b++;
		}
	}
	a < b ? cout << a : cout << b;
}
