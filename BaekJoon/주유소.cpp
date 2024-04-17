#include <iostream>
using namespace std;
int N;
int kilo[100002];
int L[100002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long total = 0;
	long long fee;
	cin >> N;
	for (int i = 1; i < N; i++) cin >> kilo[i];
	for (int i = 0; i < N; i++) cin >> L[i];
	fee = L[0];
	total += fee * kilo[1];
	for (int i = 1; i < N; i++) {
		if (fee < L[i])
			total += fee * kilo[i + 1];
		else {
			fee = L[i];
			total += fee * kilo[i + 1];
		}
	}
	cout << total;
}

