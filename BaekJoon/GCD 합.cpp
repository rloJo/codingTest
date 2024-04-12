#include <iostream>

using namespace std;

int t,n;
int a[102];
long long ans;

int GCD(int A, int B) {
	if (B == 0) return A;
	else return GCD(B, A % B);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++) {
			for (int j = i+1; j <= n; j++) {
				ans += GCD(a[i], a[j]);
			}
		}
		cout << ans << "\n";
	}

}
