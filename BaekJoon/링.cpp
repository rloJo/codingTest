#include <iostream>

using namespace std;

int N;
int rad[102];

int GCD(int a, int b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main() {
	cin >> N;
	cin >> rad[1];
	for (int i = 2; i <= N; i++) {
		int dv;
		cin >> rad[i];
		dv = GCD(rad[1], rad[i]);
		cout << rad[1]/dv << "/" << rad[i]/dv << "\n";
	}
}
