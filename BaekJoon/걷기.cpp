#include <iostream>
#include <vector>
#include <cmath>

#define X first
#define Y second

using namespace std;
long long W, S;
pair<long long, long long> ed;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

long long notCross() {
	return (ed.X + ed.Y) * W;
}

long long onlyCross() {
	long long cost = 0;
	int mod = (ed.X + ed.Y) % 2;
	cost += (max(ed.X, ed.Y) - mod) * S;
	cost += mod * W;
	return cost;
}

long long mixed() {
	long long cost = 0;
	cost += min(ed.X, ed.Y) * S;
	cost += (max(ed.X, ed.Y) - min(ed.X, ed.Y)) * W;
	return cost;
}

void input() {
	cin >> ed.X >> ed.Y >> W >> S;
}

void solution() {
	cout << min(notCross(), min(onlyCross(), mixed()));
}

int main() {
	init();
	input();
	solution();
}
