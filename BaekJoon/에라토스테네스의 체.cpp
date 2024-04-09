#include <iostream>

using namespace std;

int N;
int K;

bool eratos[1002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> K;
	eratos[0] = false;
	eratos[1] = false;
	fill(eratos, eratos + N + 1, true);

	for (int i = 2; i <= N; i++) {
		if (eratos[i])
		{
			K--;
			if (!K) {
				cout << i;
				return 0;
			}
			for (int j = i * i; j <= N; j += i) {
				if (eratos[j]) {
					eratos[j] = false;
					K--;
					if (!K) {
						cout << j;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
