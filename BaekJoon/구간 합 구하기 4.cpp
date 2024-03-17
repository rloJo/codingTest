#include <iostream>

using namespace std;

int N,M;
long long a[100002] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		a[i] = tmp + a[i - 1];
	}

	for (int i = 0; i < M; i++) {
		int ii, jj;
		cin >> ii >> jj;
		cout << a[jj] - a[ii-1] << "\n";
	}

	return 0;
}
