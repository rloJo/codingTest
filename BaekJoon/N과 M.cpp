#include <iostream>

/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

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
	for (int i = 1; i <= N; i++) { //k가 0부터 시작이기 때문에 i는 1부터 시작 이떄 i는 뽑는 카드임
		if (!vis[i]) { //i를 뽑지 않았다면
			arr[k] = i; //뽑는 카드에 i를 추가하고
			vis[i] = 1; // 뽑았다는 표시 후 재귀적으로 함수 호출
			BT(k + 1);
			vis[i] = 0; // 그리고 다시 해당 카드를 안뽑은것으로 취급
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	BT(0);
	return 0;
}
