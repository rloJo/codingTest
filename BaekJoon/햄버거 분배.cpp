#include <iostream>

using namespace std;

int N, K;
string tmp;
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	cin >> tmp;

	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] != 'P') continue;
		for (int j = i - K; j <= i + K; j++){
			if (j < 0 || j >= tmp.length()) continue;
			if (tmp[j] == 'H') {
				tmp[j] = '-';
				ans++;
				break;
			}
		}
	}
	cout << ans;
}

