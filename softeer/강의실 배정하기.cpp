#include<iostream>
#include<algorithm>

using namespace std;

/*
김교수는 강의실 1개에 최대한 많은 강의를 배정하려고 한다.
배정된 강의는 서로 겹치지 않아야 하며 수업시간의 길이와 상관없이 최대한 강의를 많이 배정하라.
단, 두 강의의 시작시간과 종료시간은 겹쳐도 된다.

제약조건
1 ≤ N ≤ 106 인 정수
1 ≤ Si ＜ Fi ≤ 109

첫 번째 줄에 최대 강의 수를 출력하라.

*/

int main(int argc, char** argv)
{
	int ans = 0;
	int N = 0;
	cin >> N;
	pair<int,int>* L = new pair<int,int>[N];
	

	for (int i = 0; i < N; i++)
		cin >> L[i].second >> L[i].first;
	//second 가 시작 시간 first가 종료 시간

	sort(L,L+N); //종료 시간을 기준으로 오름차순 정렬
	int cur = L[0].first;
	ans++;

	for (int i = 1; i < N; i++)
	{
		if (cur <= L[i].second) // 다음 강의의 시작시간이 이전 강의의 종료시간보다 크거나 같으면
		{
			cur = L[i].first;  //cur 변수를 해당 강의의 종료시간으로 변경하고 강의수 1개 증가 
			ans++;
		}
	}

	cout << ans << "\n";

	delete[] L;
	return 0;
}

//greedy 알고리즘
