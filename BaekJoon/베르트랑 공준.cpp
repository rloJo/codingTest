#include <iostream>

using namespace std;

bool eratos[250005];
int n;

void erato() {
	fill(eratos, eratos + 250000, true);
	eratos[0] = false;
	eratos[1] = false;

	for (int i = 2; i < 250000; i++) {
		if (eratos[i]) {
			for (int j = i+i; j < 250000; j += i) {
					eratos[j] = false;
			}
		}
	}
}


int main() {
	erato();

	while (1) {
		int ans = 0;
		cin >> n;
		if (!n) break;
		for (int i = n+1; i <= 2 * n; i++)
		{
			if (eratos[i]) {
				ans++;
			}
		}
		cout << ans << "\n";
	}

}
