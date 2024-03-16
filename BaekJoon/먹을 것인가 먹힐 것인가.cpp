#include <iostream>
#include <algorithm>

using namespace std;
long long A[20002];
long long B[20002];
int T;
int N, M;

bool cmp(long long a, long long b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		int ans = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int i = 0; i < M; i++)
			cin >> B[i];
		sort(A, A + N,cmp);
		sort(B, B + M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (A[i] > B[j])
					ans++;
				if (A[i] <= B[j])
					break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
