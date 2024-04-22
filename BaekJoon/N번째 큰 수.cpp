#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue <int,vector<int>,greater<int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		int num;
		cin >> num;
		if (q.size() < N) q.push(num);
		else {
			q.push(num);
			q.pop();
		}
	}

	cout << q.top() << "\n";

}

/* 메모리 계산
1bit 2진수 처리 (0or1) 2^0
1byte 8bit
1KB 1024byte 2^10 바이트
1MB 1024KB 2^10 키로바이트
1GB 1024MB 2^10 메가바이트
1TB 1024GB 2^10 기가바이트
대충 1000곱하기
*/
