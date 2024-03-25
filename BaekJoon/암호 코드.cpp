#include <iostream>

#define MOD 1000000

using namespace std;

string num;
int code[5002];
int dp[5002]; // N자리 까지 읽었을 때 나올수있는 경우의 수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> num;
	for (int i = 0; i < num.size(); i++) {
		code[i + 1] = num[i] - '0';
	}

	if (num.length() == 1 && num[0] == '0') { // 1자리 인데 0인경우
		cout << 0 << "\n";
		return 0;
	}
	
	dp[0] = 1;
	for (int i = 1; i <= num.length(); i++) {
		if (code[i] >= 1 && code[i] <= 9) { // 숫자가 1~9이면 경우의 수는 1개임 + 앞자리까지 읽는 경우의 수
			dp[i] = (dp[i - 1] + dp[i]) % MOD;
		}

		if (i == 1) continue;

		int temp = code[i] + code[i - 1] * 10; //2자리로 넘어갔을 때 앞자리*10 자기자리가 10이상 26이하이면
		if (temp >= 10 && temp <= 26) {
			dp[i] = (dp[i - 2] + dp[i]) % MOD; //앞의 숫자를 합쳐서 읽고 자신을 읽는 경우를 더해준다
		}
	}
	
	cout << dp[num.length()] << "\n";


	return 0;
}
