	#include <iostream>
	#include <vector>
	#define MAX 2000000
	using namespace std;

	int T,N,B;
	int answer = 0;
	vector<int> H;

	void init() {
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	}

	void input() {
		cin >> T;
	}

	void dfs(int height, int idx, vector<bool>& vis) {
		if (height >= B) {
			answer = min(height - B, answer);
			return;
		}

		for (int i = idx; i < N; i++) {
			if (vis[i]) continue;
			vis[i] = true;
			height += H[i];
			dfs(height,i+1, vis);
			height -= H[i];
			vis[i] = false;
		}
	}

	void solution() {
		for (int tc = 1; tc <= T; tc++) {
			cin >> N >> B;
			H = vector<int>(N);
			for (int i = 0; i < N; i++) cin >> H[i];
			vector<bool> vis(N, false);
			answer = MAX;
			dfs(0,0,vis);
			cout << "#" << tc << " " << answer << "\n";
		}
	}

	int main() {
		init();
		input();
		solution();
		return 0;
	}
