#include <iostream>

using namespace std;

int T, N;
int stock[1000002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int mx = 0;
		long long ans = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> stock[i];
		for (int i = N-1; i >=0; i--) {
			mx = max(mx, stock[i]);
			ans += mx - stock[i];
		}
		cout << ans << "\n";
	}

	return 0;
}
