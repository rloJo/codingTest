#include <iostream>
#include <vector>

using namespace std;

int T, K;
string W;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--) {
		vector<int> alpha[26];
		int shortest = 10002, longest = -1;
		cin >> W >> K;
		
		for (int i = 0; i < W.size(); i++)
			alpha[W[i] - 'a'].push_back(i);

		for (int i = 0; i < 26; i++) {
			if (alpha[i].size() < K) continue;
			int curL = 0; int curR = K - 1;
			int tmp0 = alpha[i][curR] - alpha[i][curL] + 1;
			int tmp1 = alpha[i][curR] - alpha[i][curL] + 1;
			while (curR < alpha[i].size()-1) {
				curL++; curR++;
				tmp0 = min(tmp0, alpha[i][curR] - alpha[i][curL] + 1);
				tmp1 = max(tmp1, alpha[i][curR] - alpha[i][curL] + 1);
			}
			shortest = min(tmp0, shortest);
			longest = max(tmp1, longest);
		}
		
		if (longest == -1) cout << -1 << "\n";
		else cout << shortest << " " << longest << "\n";
		
	}
	return 0;
}
