#include <iostream>
using namespace std;

int N, M; int A[1000002];
int B[1000002]; int C[2000002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];
	int curA = 0, curB = 0, curC = 0;
	while (1) {
		if(curA >= N && curB <M) {
			while (curB < M) C[curC++] = B[curB++];
			break;
		}
		if (curA < N && curB >= M) {
			while (curA < N) C[curC++] = A[curA++];
			break;
		}
		if (A[curA] <= B[curB])
			C[curC++]= A[curA++];
		else
			C[curC++] = B[curB++];
	}
	for (int i = 0; i < N + M; i++) cout << C[i] << " ";

	return 0;
}
