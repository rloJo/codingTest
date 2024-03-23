#include <iostream>

using namespace std;

int N, M;
int num[2002];
bool dp[2002][2002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> num[i];

	cin >> M;

	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1; //한자리수 
		if (i != 1 && num[i] == num[i - 1]) dp[i - 1][i] = 1; // 두자리수
	}
	
	//3자리 이상 판별
	for (int i = 2; i <= N-1; i++) { //i가 2부터 시작해야 3자리 부터 시작
		for (int j = 1; j + i  <= N; j++) {
			//ex) j=1 i=4 num[1] == num[5] 이면 dp[2][4] 2번째 자리부터 4번째 자리의 dp가 1이면 해당 수도 회문
			if (num[j] == num[i + j] && dp[j + 1][i + j - 1] == 1) {
				dp[j][j + i] = 1;
			}
		}
	}

	while (M--) {
		int S, E;
		cin >> S >> E;
		cout << dp[S][E] << "\n";
	}

	return 0;
}
