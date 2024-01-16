#include <iostream>
#include <queue>

/*
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때,
수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.


첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.
*/

using namespace std;

int dist[200002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	queue <int> Q;
	cin >> N >> K;
	if (N == K) {
		cout << 0;
		return 0;
	}

	Q.push(N);
	for (int i = 0; i < 200002; i++)
		dist[i] = -1;
	dist[N] = 0;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		 for(int x : {cur+1 , cur -1, cur*2}) { //처음 보는 방식의 for 문 좋으니까 기억
			if (x < 0 || x >= 200002) continue; //index가 넘어가면 다음 loop
			if (dist[x] !=-1) continue; // -1이 아니면 방문했던 것이라 pass
			if (x == K) {				// 다음에 만날 x가 K 이면 
				cout << dist[cur] + 1; // 현재 cur 까지의 distance + 1 하고 종료
				return 0;
			}
			dist[x] = dist[cur] + 1;  // 아니면 cur +1 저장
			Q.push(x);
		}
	}
	return 0;
}

// 잘풀었음
// 다만 dir { -1,1,2} 로 두고 2일 때 곱하는 방식이 아닌
// 새로운 방식의 for문이 더 깔끔함
