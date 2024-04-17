#include <iostream>

using namespace std;

int N,M;
int x[100002];
int mx;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> x[i];
	mx = x[1] >= (N - x[M]) ? x[1] : N - x[M];
	for (int i = 2; i <= M; i++) {
		if (mx < (x[i] - x[i - 1] + 1) / 2)
			mx = (x[i] - x[i - 1] + 1) / 2;
	}
	cout << mx;
}
