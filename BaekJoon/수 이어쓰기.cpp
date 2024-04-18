#include <iostream>
#include <string>

using namespace std;

string N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	int idx = 0;
	int ptr = 0;
	while (idx++ < 30000) {
		string tmp = to_string(idx);
		for (int i = 0; i < tmp.length(); i++) {
			if (tmp[i] == N[ptr]) ptr++;
			if (ptr == N.length()) {
				cout << idx;
				return 0;
			}
		}
	}
	return 0;
}

