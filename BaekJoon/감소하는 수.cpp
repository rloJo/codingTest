#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[11];
int cnt = 0;

int main() {
	cin >> N;
	// 감소하는 수는 10자리 수가 최대이다
	// 9876543210
	for (int i = 1; i <= 10; i++) {
		a[10 - i] = 1;
		do {
			if (cnt != N) {
				cnt++;
				continue;
			}
			// 크기가 cnt 도달할 경우 값 출력
			//a의 인덱스 0~9는 숫자 9~0에 대입된다.
			// 따라서 9-i
			for (int i = 0; i < 10; i++)
				if (a[i]) cout << 9 - i;
			return 0;
		} while (next_permutation(a,a+10));
		//각 자리수는 작은 것 부터 탐색
		//감소하는 수열을 유일, 감소하는 수열을 조합으로 구함.
	}

	cout << -1;
}
