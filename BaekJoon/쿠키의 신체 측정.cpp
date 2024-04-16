#include <iostream>

using namespace std;

int N;
char cookie[1002][1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x=0, y=0; // 심장 좌표
	int l=0, r=0, m=0, ll=0, rl=0; // 왼팔 , 오른팔, 허리 , 왼다리 , 오른다리
	cin >> N;
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> cookie[i][j];
			if (!flag && cookie[i][j] == '*')
			{
				flag = true;
				y = i;
				x = j;
			}
		}
	}

	for (int i = x - 1; ; i--) {
		if (cookie[y + 1][i] == '*') l++;
		else break;
	}

	for (int i = x + 1; ; i++) {
		if (cookie[y + 1][i] == '*') r++;
		else break;
	}

	for (int i = y + 2; ; i++) {
		if (cookie[i][x] == '*') m++;
		else break;
	}

	for (int i = y + 2 + m; ; i++) {
		if (cookie[i][x - 1] == '*') ll++;
		else break;
	}

	for (int i = y + m + 2; ; i++) {
		if (cookie[i][x + 1] == '*') rl++;
		else break;
	}

	cout << y + 1  << " " << x << "\n";
	cout << l << " " << r << " " << m << " " << ll << " " << rl;
}
