#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> node[1002];
int vis[1002];
vector <int> dfs;
vector <int> bfs;
void BFS() {
	queue<int> q;
	q.push(V);
	vis[V] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		bfs.push_back(cur);
		for (int i = 0; i < node[cur].size(); i++) {
			if (!vis[node[cur][i]]) {
				q.push(node[cur][i]);
				vis[node[cur][i]] = true;
			}
		}
	}
}

void DFS(int d) {
	vis[d] = true;
	dfs.push_back(d);
	for (int i = 0; i < node[d].size(); i++) {
		if (!vis[node[d][i]])
			DFS(node[d][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		node[s].push_back(e);
		node[e].push_back(s);
	}
	for (int i = 1; i <= N; i++) sort(node[i].begin(), node[i].end());
	BFS();
	fill(vis, vis + N + 1, false);
	DFS(V);
	for (int i = 0; i < dfs.size(); i++) cout << dfs[i] << " ";
	cout << "\n";
	for (int i = 0; i < bfs.size(); i++) cout << bfs[i] << " ";
	cout << "\n";
	return 0;
}

