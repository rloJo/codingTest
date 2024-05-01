#include <iostream>
#include <vector>

using namespace std;

int N;
int A[102];
int vis[102];
vector<int> ans;
void DFS(int cur, int st) {
	if (vis[cur]) {
		if (st == cur) ans.push_back(cur);
		return;
	}

	vis[cur] = true;
	DFS(A[cur], st);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		fill(vis, vis + N + 1, false);
		DFS(i, i);
	}
	
	cout << ans.size() << "\n";
	for (auto c : ans) cout << c << "\n";

	return 0;
}
