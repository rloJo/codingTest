#include <iostream>
#include <vector>
#include <queue>
#define MAX 0x3f3f3f3f
using namespace std;

int N, M;
vector<pair<int,int>> node[50002];
int dist[50002];

void dijkstra(int st) {
	fill(dist, dist + N + 1, MAX);
	dist[st] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({st,dist[st]});
	while (!pq.empty()) {
		pair<int, int> cur = pq.top(); pq.pop();
		if (dist[cur.first] != cur.second) continue;
		for (auto c : node[cur.first]) {
			if (dist[c.first] <= dist[cur.first] + c.second) continue;
			dist[c.first] = dist[cur.first] + c.second;
			pq.push({ c.first,dist[c.first] });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int n1, n2, w;
		cin >> n1 >> n2 >> w;
		node[n1].push_back({ n2,w });
		node[n2].push_back({ n1,w });
	}

	dijkstra(1);
	cout << dist[N];
	
	return 0;
}
