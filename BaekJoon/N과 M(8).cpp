#include <iostream>
#include <algorithm>

/*
N개의 자연수와 자연수 M이 주어졌을 때, 
아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.
*/

using namespace std;
int N, M;
int num[10]; //숫자를 받는 배열
int arr[10]; //인덱스를 저장하는 배열

void BT(int k) {
	if (k == M) { // 카드를 모두 뽑았으면 
		for (int i = 0; i < M; i++)
		{
			cout << num[arr[i]] << " "; //num배열에 해당 인덱스 호출
		}
		cout << "\n";
		return;
	}

	int start = 0; //k가 0 이면 0 부터시작
	if (k != 0) //k가 0이 아니면 오름차순으로 출력해야 하기 때문에
		start = arr[k-1]; // arr[k-1] 번 인덱스 부터 시작 배열이 정렬 되어 있기 때문에 가능

	for (int i = start ; i < N; i++) {
			arr[k] = i; //k 번째 인덱스 저장
			BT(k + 1); // 다음 카드 뽑기
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) 
		cin >> num[i];
	sort(num, num + N); //오름차순으로 배열 정렬
	BT(0);
	return 0;
}
