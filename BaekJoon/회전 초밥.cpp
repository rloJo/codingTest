#include <iostream>

using namespace std;

int N, d, k, c;
int dish[3000002];
int cnt[3002];
int first;
int ans;

int count_dish() {
	int result = 0;
	bool flag = false;
	for (int i = 1; i <= d; i++) {
		if (cnt[i]) {
			result++;
		}
		if (cnt[c]) flag = true;
	}
	
	if (flag) return result;
	else return result + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) cin >> dish[i];
	
	for (int i = 0; i < k; i++)
		cnt[dish[i]]++;

	first = 0;

	for (int i = k; i < N + k; i++) {
		cnt[dish[first]]--;
		first++;
		cnt[dish[i%N]]++;
		ans = max(count_dish(), ans);
		if (ans == k + 1) break;
	}

	cout  << ans << "\n";

	return 0;
}

