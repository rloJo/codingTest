#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int N;
int liquid[100002];
int ans = INT_MAX;
int liq_1, liq_2;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> liquid[i];
	sort(liquid, liquid + N);
	int curL = 0, curR = N - 1;
	while (curL < curR) {
		int sum = liquid[curL] + liquid[curR];
		if (abs(ans) > abs(sum)) {
			ans = sum;
			liq_1 = liquid[curL];
			liq_2 = liquid[curR];
		}

		if (ans == 0) break;
		if (sum > 0) curR--;
		else curL++;
	}
	cout << liq_1 << " " << liq_2;

	return 0;
}
