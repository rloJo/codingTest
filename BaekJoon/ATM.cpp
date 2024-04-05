#include <iostream>
#include <algorithm>

using namespace std;

int N;
int P[1002];
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> P[i];

	sort(P, P + N);

	for (int i = 0; i < N; i++)
		ans += P[i] * (N-i);

	cout << ans;
	return 0;
}
