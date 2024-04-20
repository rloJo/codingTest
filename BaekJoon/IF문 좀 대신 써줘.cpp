#include <iostream>

using namespace std;

int N, M;
pair<string, int> call[100002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> call[i].first >> call[i].second;
	for (int i = 0; i < M; i++) {
		int stat;
		cin >> stat;
		int st = 0; int end = N - 1;
		while (st < end) {
			int mid = (st + end) / 2;
			if (call[mid].second < stat) st = mid + 1;
			else end = mid;
		}

		cout << call[end].first << "\n";
	}
	return 0;
}

/*
Lower Bound K이상이 처음 나오는 위치

while(left < rigth)
{
	int mid = (left + right) /2;
	if(arr[mid] < K) left = mid+1;
	else right = mid;
}

right 에 처음 나오는 index 반환
------------------------------------------

Upper Bound K초과가 처음 나오는 위치

while(left < rigth)
{
	int mid = (left + right) /2;
	if(arr[mid] > K) right = mid;
	else left = mid + 1;
}

left에 반환

*/
