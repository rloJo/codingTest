#include <iostream>

using namespace std;

int T,N;
long long arr[102] = { 0,1,1,1,2,2,3,4,5,7,9 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 11;	i <= 100; i++) {
		arr[i] = arr[i - 5] + arr[i - 1];
	}

	cin >> T;
	while (T--) {
		cin >> N;
		cout << arr[N] << "\n";
	}

	return 0;
}
