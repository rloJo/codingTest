#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int F, S, G, U, D;
int cnt[1000001];

bool OOB(int x) {
	return x <= 0 || x > F;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> F >> S >> G >> U >> D;
	int dir[2] = { U,-D };
	queue<int> Q;
	Q.push(S);
	cnt[S] = 1;
	
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int i = 0; i < 2; i++) {
			int nxt = cur + dir[i];
			if (OOB(nxt) || cnt[nxt] > 0) continue;
			Q.push(nxt); 
			cnt[nxt] = cnt[cur] + 1;
		}
	}
	
	if (!cnt[G]) cout << "use the stairs";
	else cout << cnt[G]-1;

	return 0;
}
