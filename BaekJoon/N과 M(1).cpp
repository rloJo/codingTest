#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
bool vis[10];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N >> M;
}

void tracking(int k) {
	if (k == M) {
		for(int i=0;i<M;i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (vis[i]) continue;
		arr[k] = i;
		vis[i] = true;
		tracking(k + 1);
		vis[i] = false;
	}
}


void solution() {
	tracking(0);
}

int main() {
	init();
	input();
	solution();
}
