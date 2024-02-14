#include <iostream>
#include <algorithm>

/*
N개의 자연수와 자연수 M이 주어졌을 때, 
아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.
*/

using namespace std;
int N, M;
int num[10]; //숫자를 받는 배열
int arr[10]; //뽑은 카드를 저장하는 배열

void BT(int k) {
	if (k == M) { // 카드를 모두 뽑았으면 
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " "; //뽑은 카드 출력
		}
		cout << "\n";
		return;
	}

	int tmp = 0; //이전 수열의 마지막 항과 새로 뽑는 카드의 값이 같으면 중복 수열
	for (int i = 0; i < N; i++) {
		if (tmp !=num[i]) {
			arr[k] = num[i];
			tmp = arr[k];
			BT(k + 1); // 다음 카드 뽑기
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) 
		cin >> num[i];
	sort(num, num + N); 
	BT(0);
	return 0;
}
