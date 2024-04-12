#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int N;
int k;
int ans; //마지막 사용 수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> k;
	int len = 1; //자릿수
	int exp = 1; //1~9 9자리 차지 10~99 90자리 차지 ...

	while (k > 9LL * len * exp) {
		k -= 9LL * len * exp;
		exp *=10;
		len++;
	}

	if (len == 1) { //한자리 수 일 때 처리
		if (N < k) cout << -1;
		else cout << k;
		return 0;
	}
	
	// 두자리 수 이상일 때
	int ans = exp -1; //ex) 자리수가 2일 때 9를 마지막으로 사용

	for (int i = 1; i <= k / len; i++) ans++; //자리수 만큼 나눠서 마지막 사용한 수 갱신

	if (k%len != 0) //k가 exp와 나누어 떨어지지 않으면 1 증가
		ans++;

	if (ans > N) cout << -1; //마지막 사용한 수가 N보다 크면 -1 출력
	else {
		string tmp = to_string(ans);
		k% len == 0 ? cout << tmp[tmp.length() - 1] : cout << tmp[(k % len)-1];
		//나머지가 0이면 마지막 자리수 출력 그 외 나머지 -1 자리 출력
	}
	
}
