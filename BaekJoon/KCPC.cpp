#include <iostream>

using namespace std;

class info {
public:
	int time = 0;
	int last = 0;
	int total = 0;
};

int T;
int n, k, ID, m;
int score[102][102];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> n >> k >> ID >> m;
		info team[102];
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100; j++)
				score[i][j] = 0;
		}

		for (int i = 1; i <= m; i++) {
			int id, j, s;
			cin >> id >> j >> s;
			score[id][j] = max(score[id][j], s);
			team[id].time++;
			team[id].last = i;
		}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= k; j++)
				team[i].total += score[i][j];

		int ans = 1;
		for (int i = 1; i <= n; i++) {
			if (i == ID) continue;
			if (team[i].total > team[ID].total) ans++;
			else if (team[i].total == team[ID].total) {
				if (team[i].time < team[ID].time) ans++;
				else if (team[i].time == team[ID].time) {
					if (team[i].last < team[ID].last) ans++;
				}
			}
		}

		cout << ans << "\n";
	}
	return 0;
}

