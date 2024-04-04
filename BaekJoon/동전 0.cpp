#include <iostream>

using namespace std;

int N,K;
int A[12];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	
	for (int i = N; i >= 1; i--) {
		ans += K / A[i];
		K %= A[i];
		if (K == 0)
			break;
	}

	cout << ans << "\n";

	return 0;
}
