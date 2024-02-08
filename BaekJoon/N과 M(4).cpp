#include <iostream>

/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
*/

using namespace std;
int N, M;
int arr[10];
int vis[10];

void BT(int k) {

	if (k == M) { //k가 M이랑 같아지면 뽑을 수 있는 수가 0 따라서 출력
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return;
	}
	int start = 1; //아무 카드가 없으면 시작 카드는 1
	if (k != 0) start = arr[k - 1]; //카드가 있으면 해당 카드 숫자 부터 시작 (중복이 가능하고, 오름차순이기 때문에)
	for (int i = start; i <= N; i++) { //k가 0부터 시작이기 때문에 i는 1부터 시작 이떄 i는 뽑는 카드임
		arr[k] = i; //뽑는 카드에 i를 추가하고
		BT(k + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	BT(0);
	return 0;
}
