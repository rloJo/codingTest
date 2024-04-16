#include <iostream>

using namespace std;

class country {
public:
	int gold;
	int silver;
	int bronze;
};

int N, K;
country result[1002];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int id;
		cin >> id;
		cin >> result[id].gold >> result[id].silver >> result[id].bronze;
	}

	for (int i = 1; i <= N; i++) {
		if (result[i].gold > result[K].gold) ans++;
		else if (result[i].gold == result[K].gold) {
			if (result[i].silver > result[K].silver) ans++;
			else if (result[i].silver == result[K].silver) {
				if (result[i].bronze > result[K].bronze) ans++;
			}
		}
	}
	cout << ans + 1;
}
