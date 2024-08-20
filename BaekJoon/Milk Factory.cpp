#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> conveyor(102);

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int from, to;
		cin >> from >> to;
		conveyor[to].push_back(from);
	}
}

bool bfs(int station) {
	vector<int> vis(N + 1);
	queue<int> Q;
	Q.push(station);
	vis[station] = true;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int i = 0; i < conveyor[cur].size(); i++) {
			if (vis[conveyor[cur][i]]) continue;
			Q.push(conveyor[cur][i]);
			vis[conveyor[cur][i]] = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (i == station) continue;
		if (!vis[i]) return true;
	}

	return false;
}

void solution() {
	int answer = N*100;
	for (int i = 1; i <= N; i++) {
		if (!bfs(i)) answer = min(answer, i);
	}
	if (answer < N) cout << answer;
	else cout << -1;
}

int main() {
	init();
	input();
	solution();
}
