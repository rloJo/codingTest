#include <iostream>

/*
사다리 게임은 N개의 세로선과 M개의 가로선으로 이루어져 있다.
인접한 세로선 사이에는 가로선을 놓을 수 있는데,
각각의 세로선마다 가로선을 놓을 수 있는 위치의 개수는 H이고, 모든 세로선이 같은 위치를 갖는다.
아래 그림은 N = 5, H = 6 인 경우의 그림이고, 가로선은 없다.

초록선은 세로선을 나타내고, 초록선과 점선이 교차하는 점은 가로선을 놓을 수 있는 점이다.
가로선은 인접한 두 세로선을 연결해야 한다. 단, 두 가로선이 연속하거나 서로 접하면 안 된다.
또, 가로선은 점선 위에 있어야 한다.

위의 그림에는 가로선이 총 5개 있다.
가로선은 위의 그림과 같이 인접한 두 세로선을 연결해야 하고, 가로선을 놓을 수 있는 위치를 연결해야 한다.

사다리 게임은 각각의 세로선마다 게임을 진행하고, 세로선의 가장 위에서부터 아래 방향으로 내려가야 한다.
이때, 가로선을 만나면 가로선을 이용해 옆 세로선으로 이동한 다음, 이동한 세로선에서 아래 방향으로 이동해야 한다.

위의 그림에서 1번은 3번으로, 2번은 2번으로, 3번은 5번으로, 4번은 1번으로, 5번은 4번으로 도착하게 된다.
아래 두 그림은 1번과 2번이 어떻게 이동했는지 나타내는 그림이다.


1번 세로선	2번 세로선
사다리에 가로선을 추가해서, 사다리 게임의 결과를 조작하려고 한다.
이때, i번 세로선의 결과가 i번이 나와야 한다.
그렇게 하기 위해서 추가해야 하는 가로선 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 세로선의 개수 N, 가로선의 개수 M,
세로선마다 가로선을 놓을 수 있는 위치의 개수 H가 주어진다. (2 ≤ N ≤ 10, 1 ≤ H ≤ 30, 0 ≤ M ≤ (N-1)×H)
둘째 줄부터 M개의 줄에는 가로선의 정보가 한 줄에 하나씩 주어진다.
가로선의 정보는 두 정수 a과 b로 나타낸다.
(1 ≤ a ≤ H, 1 ≤ b ≤ N-1) b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는 의미이다.
가장 위에 있는 점선의 번호는 1번이고, 아래로 내려갈 때마다 1이 증가한다.
세로선은 가장 왼쪽에 있는 것의 번호가 1번이고, 오른쪽으로 갈 때마다 1이 증가한다.
입력으로 주어지는 가로선이 서로 연속하는 경우는 없다.
*/

using namespace std;

int N, M, H;
bool board[32][12];
bool flag = false;
int add_ladder = 0;
bool check() { // 사다리 결과 확인 조작 성공 => 1 실패 => 0
	for (int i = 0; i < N; i++) {
		pair<int, int> start = { 0,i }; //시작 지점
		while (start.first < H) {
			if (board[start.first][start.second]) //해당 칸이 1이면 열 1 증가
				start.second += 1;

			else if (start.second > 0 && board[start.first][start.second - 1]) //해당 칸 전 열이 1이면 열 -1
				start.second -= 1;

			start.first += 1; //가로선 1 증가
		}

		if (start.second != i)
			return false;
	}

	return true;
}

void dfs(int k, int cnt) {
	if (add_ladder == cnt) { //증가한 사다리 개수 0부터 시작
		if (check())
			flag = true;
		return;
	}

	for (int i = k; i < H; i++) {
		for (int j = 0; j < N; j++) {
			//해당칸이 놓을 수 있는 사다리면
			if (board[i][j - 1] != 1 && board[i][j] != 1 && board[i][j + 1] != 1)
			{
				//해당칸에 사다리 추가 
				board[i][j] = true;
				dfs(i, cnt + 1); // 사다리 추가 후 탐색 해당 행부터 시작!
				board[i][j] = false;
				// 해당 사다리 지우기
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		pair<int, int> ladder;
		cin >> ladder.first >> ladder.second;
		board[ladder.first - 1][ladder.second] = 1;
		// board가 true이면 해당 열에서 열+1 로 이동하는 사다리
	}

	for (int i = 0; i <= 3; i++) {
		add_ladder = i; // 사다리는 0개부터 3개 까지 가능
		dfs(0, 0);
		if (flag) {
			cout << add_ladder << "\n";
			return 0;
		}
	}

	cout << -1 << "\n"; //실패한 경우
	return 0;
}
