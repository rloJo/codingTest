#include <iostream>

using namespace std;

string S;
int cnt1 = 0;
int cnt0 = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] - '0') cnt1++;
		if (!(S[i] - '0')) cnt0++;
	}

	cnt1 /= 2; cnt0 /= 2;
	
	int cur1 = 0; int cur0 = S.length() - 1;
	while (cnt1 > 0 || cnt0 > 0)
	{
		if (S[cur1]=='1' && cur1 < S.length()) {
			if (cnt1 > 0) {
				S[cur1] = '-';
				cnt1--;
			}		
		}

		if (S[cur0] == '0' && cur0 >= 0) {
			if (cnt0 > 0) {
				S[cur0] = '-';
				cnt0--;
			}
		}
		cur1++; cur0--;
	}

	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '-') continue;
		else cout << S[i];
	}

	return 0;
}

