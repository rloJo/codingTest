#include<iostream>
#include<deque>

using namespace std;
/*
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 N(0 ≤ N ≤ 100, 000)에 있고, 
동생은 점 K(0 ≤ K ≤ 100, 000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다.
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X - 1 또는 X + 1로 이동하게 된다.
순간이동을 하는 경우에는 0초 후에 2 * X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때,
수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. 
N과 K는 정수이다.
*/

int vis[200005];
int N, K;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(vis, vis + 200000, 100000); //최대한 큰수로 vis배열 초기화
	deque<int> Q;
	cin >> N >> K;
	Q.push_back(N);
	vis[N] = 0;

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop_front();
		if (2 * cur < 200000 && vis[2 * cur] == -1 || 2 * cur < 200000 && vis[2*cur] > vis[cur]) {
			Q.push_front(cur * 2);
			vis[2 * cur] = vis[cur];
		}

		for (auto i : { 1, -1}) {
			int nx = cur +i;
			if (nx < 0 || i >= 200000) continue;
			if (vis[nx] <= vis[cur]+1) continue; //방문할 것이 현재 방문 시간 +1 보다 작으면 넘김
			Q.push_back(nx);
			vis[nx] = vis[cur] + 1;
		}
	}

	cout << vis[K];
}


/*
0-1 BFS 문제
deque를 사용해 0초가 걸리는 것은 앞에 넣고 
1초가 걸리는 것은 뒤에 넣는 것이 핵심

vis 가 -1일때를 검사 하면 cur -1, 1 순서에 따라 오답이 되는 경우가 있음 
따라서 -1일떄를 검사하는 것이 아닌 시간에 따라 조건을 구별해야함
4 6 일때 오류가 생김
4 -> 3 -> 6  1 인데 2로 발생하는 오류 

*/
