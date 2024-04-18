#include <iostream>
using namespace std;

int N, X;
int vis[250002];
int a[250002];
int ans = 0;
int mx = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> X;
	for (int i = 1; i <= N; i++) cin >> vis[i];
	for (int i = 1; i <= X; i++) a[1] += vis[i];
	mx = a[1];
	ans = 1;

	for (int i = 2; i <= N-X +1; i++) {
		a[i] = a[i - 1] - vis[i - 1] + vis[i + X -1];
		if (mx < a[i]) {
			mx = a[i];
			ans = 1;
		}
		else if (mx == a[i]) {
			ans++;
		}
	}

	if (mx != 0)
		cout << mx << "\n" << ans;
	else
		cout << "SAD";

	return 0;
}

