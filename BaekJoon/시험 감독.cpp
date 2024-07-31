#include <iostream>

using namespace std;

int N;
int A[1000002];
int B, C;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> B >> C;
}

void solution() {
	long long answer = 0;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		answer++;
		if (A[i] <= 0) continue;
		answer += (A[i] % C == 0) ? (long long) (A[i] / C) :(long long) (A[i] / C) + 1;
	}

	cout << answer << "\n";

}

int main() {
	init();
	input(); 
	solution();
}
