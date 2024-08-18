#include <iostream>
#include <vector>
#include <queue>
#define link first  
#define usado second

using namespace std;

int N, Q;
vector<pair<int, int>> video[5002];
vector<pair<int, int>> ask;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N >> Q;
	for (int i = 0; i < N-1; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		video[p].push_back({ q,r });
		video[q].push_back({ p,r });
	}
	for (int i = 0; i < Q; i++) {
		int k, v;
		cin >> k >> v;
		ask.push_back({ k,v });
	}
}

int BFS(int k, int v) {
	vector<bool> vis(5002, false);
	int answer = 0;
	queue<int> Q;
	Q.push(v);
	vis[v] = true;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int i = 0; i < video[cur].size(); i++) {
			int ncur = video[cur][i].link;
			int nusado = video[cur][i].usado;
			if (vis[ncur]) continue;
			if (nusado < k) continue;
			vis[ncur] = true;
			Q.push(ncur);
			answer++;
		} 
	}
	return answer;
}

void solution() {
	for (int i = 0; i < ask.size(); i++) {
		cout << BFS(ask[i].first, ask[i].second) << "\n";
	}
}

int main() {
	init();
	input();
	solution();
}
