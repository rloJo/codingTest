#include <iostream>
#include <vector>
#include <cmath>

#define X first 
#define Y second

using namespace std;

int dist = 0;
int N;
vector<pair<int, int>> checkPoint;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	int x, y;
	cin >> N;
	cin >> x >> y;
	checkPoint.push_back({ x,y });
	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		checkPoint.push_back({ x,y });
		dist += abs(checkPoint[i].X - checkPoint[i - 1].X) + abs(checkPoint[i].Y - checkPoint[i - 1].Y);
	}
}

void solution() {
	int diff = 0;
	for (int i = 1; i < checkPoint.size() - 1; i++) {
		pair<int, int> prev = checkPoint[i - 1];
		pair<int, int> cur = checkPoint[i];
		pair<int, int> next = checkPoint[i + 1];
		int go = abs(prev.X - cur.X) + abs(prev.Y - cur.Y) + abs(cur.X - next.X) + abs(cur.Y - next.Y);
		int skip = abs(prev.X - next.X) + abs(prev.Y - next.Y);
		diff = max(diff, go - skip);
	}
	cout << dist - diff << "\n";
}

int main() {
	init();
	input();
	solution();
}


