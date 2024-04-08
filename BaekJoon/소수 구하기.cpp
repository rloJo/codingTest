#include <iostream>
#define MAX 1000001

using namespace std;

int M, N;
bool eratos[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;

	fill(eratos, eratos + N +2, true);
	eratos[0] = false;
	eratos[1] = false;

	for (int i = 2; i * i < MAX; i++) {
		if (eratos[i]) // 소수 이면
		{
			for (int j = i * i; j < MAX; j += i) { //소수로 인해 나올 수 있는 곱값 제거
				eratos[j] = false;
			}
		}
	}

	for (int i = M; i <= N; i++)
		if (eratos[i]) cout << i << "\n";
	

	return 0;
}
