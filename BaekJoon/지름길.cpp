#include <iostream>
#include <climits>

using namespace std;

class way {
public:
	int st = 0;
	int end = 0;
	int dist = 0;
};

int N, D;
way load[13];
int dp[10002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		way l;
		cin >> l.st >> l.end >> l.dist;
		load[i] = l;
	}

	fill(dp, dp + 10001, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= D; i++) {
		for (int j = 0; j < N; j++) {
			if (load[j].end == i) {
				dp[i] = min(dp[i], dp[load[j].st] + load[j].dist);
			}
			dp[i] = min(dp[i],dp[i-1] +1);
		}
	}

	cout << dp[D] << "\n";

	return 0;
}

