#include <iostream>
/*
n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다.
ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다. 
자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 
(ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 수열의 크기 n이 주어진다. 다음 줄에는 수열에 포함되는 수가 주어진다. 
셋째 줄에는 x가 주어진다. (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000)

*/

using namespace std;

bool idx[2000001] = { false };
int a[1000001] = { 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	int ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> x;

	for (int i = 0; i < n; i++)
	{
		//x-a[i] 가 0 이상이여만 가능 
		// x-a[i]번째 idx 배열에 값이 없으면 해당 시점에서 
		//해당 값은 x를 만들 수 없음
		if (x -a[i]>0 && idx[x-a[i]])
			ans++;
		idx[a[i]] = true;
	}

	cout << ans << "\n";
}
