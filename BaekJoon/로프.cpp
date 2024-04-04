#include <iostream>
#include <algorithm>

using namespace std;

int N;
int w[100002];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> w[i];
	
	sort(w, w + N);

	for (int i = 1; i <= N; i++) {
		ans = max(ans, w[N - i] * i);
	}

	cout << ans;

	return 0;
}
