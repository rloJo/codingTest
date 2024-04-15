#include <iostream>

using namespace std;

int N;
int cnt = 1;
int fl = 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (cnt < N) {
		cnt += 6* fl;
		fl++;
	}
	cout << fl;
}
