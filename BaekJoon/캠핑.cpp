#include <iostream>

using namespace std;

int L, P, V;
int cnt = 1;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> L >> P >> V;
		if (!L && !P && !V) break;
		ans = (V / P * L);
		if (V % P >= L) ans += L;
		else ans += V % P;
		cout << "Case " << cnt++ << ": " << ans << "\n";
	}

	return 0;
}
