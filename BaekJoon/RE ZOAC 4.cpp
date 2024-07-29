#include <iostream>

using namespace std;

int H, W, N, M;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> H >> W >> N >> M;
}

void solution() {
	int w = W % (1 + M) > 0 ? W/(1+M)+1 : W / (1 + M);
	int h = H % (1 + N) > 0 ? H/(1+N)+1 : H/  (1+ N);

	cout << w * h << "\n";
}

int main() {
	init();
	input();
	solution();
}
