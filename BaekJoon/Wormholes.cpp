#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
struct Hole {
	int x;
	int y;
	int connect;
};

int answer = 0;
vector<Hole> wormholes;
vector<bool> connected(13,false);

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

bool cmp(Hole a, Hole b) {
	return a.x < b.x;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y; 
		cin >> x >> y;
		wormholes.push_back({ x,y,-1 });
	}
	sort(wormholes.begin(), wormholes.end(),cmp);
}

pair<bool,int> nextHole(int hole)
{
	for (int i = 0; i < N; i++) {
		if (wormholes[i].x > wormholes[hole].x && wormholes[i].y == wormholes[hole].y) return {true, i};
	}
	return {false, -1};
}

bool isLoop(int idx) {
	vector<bool> vis(13, false);
	while (1) {
		if (vis[idx]) return true;
		vis[idx] = true;
		idx = wormholes[idx].connect;
		pair<bool, int> result = nextHole(idx);
		if (result.first) idx = result.second;
		else return false;
	}
}

void connectHole(int cnt, int index ) {
	if (cnt == N) {
		for (int i = 0; i < N; i++) {
			if (isLoop(i)) {
				answer++;
				return;
			}
		}
	}

	for (int i = index; i < N; i++) {
		if (connected[i]) continue;
		connected[i] = true;
		for (int j = i + 1; j < N; j++) {
			if (connected[j]) continue;
			connected[j] = true;
			wormholes[i].connect = j;
			wormholes[j].connect = i;
			connectHole(cnt + 2, i+1);
			connected[j] = false;
		}
		connected[i] = false;
	}
}

void solution() {
	connectHole(0, 0);
	cout << answer << "\n";
}

int main() {
	init();
	input();
	solution();
}
