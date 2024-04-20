#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int N;
priority_queue<int,vector<int>, greater<int>> h;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		if (x > 0) h.push(x);
		if (x == 0) {
			if (h.empty()) cout << 0 << "\n";
			else {
				cout << h.top() << "\n";
				h.pop();
			}
		}
	}
}

