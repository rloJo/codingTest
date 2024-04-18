#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int m[10002];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) cin >> m[i];
	cin >> M;

	sort(m, m + N);
	int st = 0; // 금액의 최소는 0
	int end = m[N - 1]; // 금액의 최대
	int result;

	while (st <= end) {
		int sum = 0;
		int mid = (st + end) / 2; // 금액의 중간값
		for (int i = 0; i < N; i++) sum += min(m[i], mid); // 배정해야할 액수랑 중간값 비교
		if (M >= sum) { // 총 액수가 더 크면
			result = mid; //최대 정수 mid
			st = mid + 1;
		}
		else //총 액수가 작으면 end값 수정
			end = mid - 1;
	}

	cout << result;
	
	return 0;
}

