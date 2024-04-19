#include <iostream>
#include <cmath>

using namespace std;

int N;
int alpha[102][26];

void cnt(string tmp, int id) {
	for (int i = 0; i < tmp.length(); i++) {
		alpha[id][tmp[i] - 'A']++;
	}
}

int check() {
	int ans = 0;
	for (int i = 2; i <= N; i++)
	{
		bool w1 = true;
		bool w2 = true; int cnt2 = 0;
		bool w3 = true; int cnt_31 = 0; int cnt_32 = 0;

		for (int j = 0; j < 26; j++) {
			// 모두 같은 구성인 경우
			if (alpha[1][j] != alpha[i][j])
				w1 = false;

			//한단어에서 한문자를 빼거나 더하는 경우
			if (abs(alpha[1][j] - alpha[i][j]) == 1) {
				if (cnt2) w2 = false;
				cnt2++;
			}
			else if (abs(alpha[1][j] - alpha[i][j]) > 1){
				w2 = false; w3 = false;
			}

			//한단어에서 한문자를 바꾸는 경우
			if (alpha[1][j] - alpha[i][j] == 1)
				cnt_31++;
			if (alpha[i][j] - alpha[1][j] == 1)
				cnt_32++;		
		}

		if (cnt_31 != cnt_32 || cnt_31 != 1 || cnt_32 != 1)
			w3 = false;

		if (w1||w2||w3) ans++;
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		cnt(tmp, i);
	}
	
	cout << check();

	return 0;
}

