#include <iostream>
#include <queue>
#include <tuple>
#define Cost first
#define Node second

using namespace std;

int V, E;
bool vis[10002];

//비용 정점 번호
vector<pair<int, int>> adj[10005];

// 비용 정점 1 정점2
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		adj[A].push_back({ C,B });
		adj[B].push_back({ C,A });
	}
}

void solution() {
	int answer = 0;
	int cnt = 0;
	vis[1] = true;
	for (auto next : adj[1]) Q.push({ next.Cost, 1, next.Node });
	
	while (cnt < V - 1) {
		int cost, a, b;
		tie(cost, a, b) = Q.top(); Q.pop();
		if (vis[b]) continue;
		answer += cost;
		vis[b] = true;
		cnt++;
		for (auto next : adj[b]) Q.push({ next.Cost, b, next.Node });
	}

	cout << answer;
}

int main() {
	init();
	input();
	solution();
}
