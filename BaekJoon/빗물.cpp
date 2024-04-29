#include <iostream>

using namespace std;

int H, W;
int block[502];
int ans = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> H >> W;
	for (int i = 0; i < W; i++)
		cin >> block[i];

	for(int i = 1;i < W-1;i++){
		int curL = 0; int curR = 0;
		for (int j = i - 1; j >= 0; j--) curL = max(block[j], curL); 
		for (int j = i + 1; j < W; j++) curR = max(block[j], curR);
		ans += max(0, min(curL, curR) - block[i]);
	}
	
	cout << ans;
	return 0;
}
