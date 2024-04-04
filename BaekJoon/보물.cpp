#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[52];
int B[52];
int ans;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++)
		cin >> B[i];
	
	sort(A, A + N);
	sort(B, B + N, cmp);

	for (int i = 0; i < N; i++)
		ans += A[i] * B[i];

	cout << ans;

	return 0;
}
