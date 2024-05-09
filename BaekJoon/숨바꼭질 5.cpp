#include <iostream>
#include <queue>

#define mark 500000
using namespace std;

int N, K;
int ans;
int dx[3] = { -1,1,2 };
bool vis[2][500002];

bool OOB(int x) {
	return x < 0 || x > mark;
}

void bfs() {
	int mov = 1;
	queue<int> Q;
	Q.push(N);

	if (N == K) {
		ans = 0;
		return;
	}

	while (!Q.empty()) {
		K += mov; // 동생 위치 조정

		if (K > mark) { 
			ans = -1;
			return; 
		}
		if (vis[mov % 2][K]) {
			ans = mov;
			return;
		}


		// bfs에서 깊이를 세기위한 테크닉 *
		// q사이즈로 깊이를 알수 있음(깊이는 즉 이동한 초)
		int Qsize = Q.size();

		for (int i = 0; i < Qsize; i++) {
			int x = Q.front();
			Q.pop();

			for (int dir = 0; dir < 3; dir++) {
				int nx = x + dx[dir];
				if (dir == 2) nx = x * 2;
				if (nx == K) {
					ans = mov;
					return;
				}
				if (OOB(nx)) continue;
				if (vis[mov % 2][nx]) continue;
				vis[mov % 2][nx] = true;
				Q.push(nx);
			}
		}
		mov++; // 깊이마다 동생이 이동한 거리 증가
	}
}
//mov%2의 의미
// 만약에 수빈이가 x초에 해당 점에 방문을 했었으면 x+2 x+4 x+6 ... 초에도 방문을 할 수 있음
// 따라서 해당 좌표에 짝수 또는 홀수 초에 도착을 했었으면 다시 그때로 도달 가능

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	bfs();
	cout << ans;
	
	return 0;
}
