#include <iostream>
#include <deque>
/*
지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다. 지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.
지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.
첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
큐에 처음에 포함되어 있던 수 N이 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다.
(이 위치는 가장 처음 큐에서의 위치이다.) 이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다.
N은 50보다 작거나 같은 자연수이고, M은 N보다 작거나 같은 자연수이다.
둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다. 
위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.
*/
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M,ans=0;
	cin >> N >> M;
	deque<int> arr;
	for (int i = 0; i < N; i++)
		arr.push_back(i + 1);

	for (int i = 0; i < M; i++)
	{
		int num = 0;
		int idx = 0;
		cin >> num;

		//찾으려는 숫자의 인덱스를 찾는다
		for (int j = 0; j < N; j++)
		{
			if (num == arr.at(j))
			{
				idx = j;
				break;
			}
		}

		//찾은 인덱스가 덱의 사이즈/2 보다 작으면
		// 왼쪽에 있는 경우로 왼쪽 이동 수행 (2번)
		if (idx <= arr.size()/2)
		{
			//왼쪽이동연산을 idx번 수행해야 front로 해당 카드가 옴
			for (int j = 0; j < idx; j++)
			{
				arr.push_back(arr.front());
				arr.pop_front();
				ans++;
			}
			arr.pop_front();
		} 
		//찾은 인덱스가 반보다 오른쪽에 있으면
		// size - idx만 큼 오른쪽 이동 실행 (3번)
		else {
			//오른쪽이동을 size - idx 번해야 front로 해당 카드옴
			// idx는 0부터 시작하기때문에 
			// 1~10 카드에서 7이면 
			// idx = 6 임을 기억
			for (int j = 0; j < arr.size() - idx; j++)
			{
				arr.push_front(arr.back());
				arr.pop_back();
				ans++;
			}
			arr.pop_front();
		}
	}

	cout << ans;
	return 0;
}
