#include <iostream>
#include <vector>
#include <cmath>

#define MAX 200000
#define X first
#define Y second
using namespace std;


int test_case;
int answer;
pair<int, int> company, home;
vector<pair<int, int>> client;
int N;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	client = vector<pair<int, int>>(N);
	cin >> company.X >> company.Y >> home.X >> home.Y;
	for (int i = 0; i < N; i++) {
		cin >> client[i].X >> client[i].Y;
	}
}

void dfs(pair<int,int> before, int cnt, int minWay, vector<bool>&vis) {
	if (minWay >= answer) return;

	if (cnt == N) {
		minWay += abs(before.X - home.X) + abs(before.Y - home.Y);
		answer = min(answer, minWay);
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		int distance = abs(before.X - client[i].X) + abs(before.Y - client[i].Y);
		minWay += distance;
		dfs(client[i], cnt + 1, minWay, vis);
		minWay -= distance;
		vis[i] = false;
	}
}

void solution() {
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		answer = MAX;
		input();
		vector<bool> vis(N, false);
		dfs(company, 0, 0, vis);
		cout << "#" << tc << " " << answer << "\n";
	}
}

int main() {
	init();
	solution();
	return 0;
}
