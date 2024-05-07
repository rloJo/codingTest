#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int N, K;
int dx[3] = { -1,1,2 };

int vis[100002];
int way[100002];
stack<int> ans;

bool OOB(int x) {
	return x < 0 || x >  100000;
}

void bfs() {
	queue<int> Q;
	Q.push(N);
	vis[N] = 1;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 3; dir++) {
			int nx = cur + dx[dir];
			if (dir == 2) nx = cur * 2;
			if (OOB(nx) || vis[nx]) continue;
			Q.push(nx);
			vis[nx] = vis[cur] + 1;
			way[nx] = cur;
			if (nx == K) return;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;

	bfs();
	cout << vis[K] - 1 << "\n";
	
	int idx = K;
	while (1) {
		ans.push(idx);
		if (idx == N)break;
		idx = way[idx];
	}
	
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}

	return 0;
}
