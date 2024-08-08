#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int answer = 0;
string road;
int dp[3][3][3][3];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
	cin >> road;
}

void solution() {
	dp[0][0][0][0] = 1;
	int t = 0, g = 0, f = 0, p = 0;
	for (int i = 0; i < road.size(); i++) {
		if (road[i] == 'T') t = (t + 1) % 3;
		if (road[i] == 'G') g = (g + 1) % 3;
		if (road[i] == 'F') f = (f + 1) % 3;
		if (road[i] == 'P') p = (p + 1) % 3;
		answer += dp[t][g][f][p];
		dp[t][g][f][p]++;
	}
	cout << answer << "\n";
}

int main() {
	init();
	input();
	solution();
}
