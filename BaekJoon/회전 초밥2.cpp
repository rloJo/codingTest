#include <iostream>

using namespace std;

int N, d, k, c;
int dish[3000002];
int cnt[3002];
bool flag = false;
int total = 0;
int first;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) cin >> dish[i];

	for (int i = 0; i < k; i++) {
		cnt[dish[i]]++;
	}

	first = 0;

	for (int i = 1; i <= d; i++) {
		if (cnt[i]) total++;
		if (cnt[c]) flag = true;
	}

	if (!flag) total++;
	ans = total;
	
	for (int i = k; i < N + k-1; i++) {
		if (!flag) total--;

		cnt[dish[first]]--;
		if (!cnt[dish[first]]) total--;
		if (!cnt[dish[i % N]]) total++;
		cnt[dish[i % N]]++;
		first++;
		
		if (cnt[c]) flag = true;
		else flag =	false;

		if (!flag) total++;
	
		ans = max(total, ans);
		if (ans == k + 1) break;
	}

	cout << ans << "\n";

	return 0;
}
