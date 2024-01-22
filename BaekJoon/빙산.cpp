#include<iostream>
#include<queue>

using namespace std;
/*
지구 온난화로 인하여 북극의 빙산이 녹고 있다. 빙산을 그림 1과 같이 2차원 배열에 표시한다고 하자.
빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다.
빙산 이외의 바다에 해당되는 칸에는 0이 저장된다.
그림 1에서 빈칸은 모두 0으로 채워져 있다고 생각한다.

    2	4	5	3
    3	 	2	5	2
    7	6	2	4

그림 1. 행의 개수가 5이고 열의 개수가 7인 2차원 배열에 저장된 빙산의 높이 정보
빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어들기 때문에,
배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다.
단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다.
바닷물은 호수처럼 빙산에 둘러싸여 있을 수도 있다.
따라서 그림 1의 빙산은 일년후에 그림 2와 같이 변형된다.
그림 3은 그림 1의 빙산이 2년 후에 변한 모습을 보여준다.
2차원 배열에서 동서남북 방향으로 붙어있는 칸들은 서로 연결되어 있다고 말한다
따라서 그림 2의 빙산은 한 덩어리이지만, 그림 3의 빙산은 세 덩어리로 분리되어 있다.

        2	4	1
    1	 	1	5
    5	4	1	2

그림 2

            3
                4
    3	2

그림 3

한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오.
그림 1의 빙산에 대해서는 2가 답이다.
만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.

첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다.
N과 M은 3 이상 300 이하이다.
그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다.
각 칸에 들어가는 값은 0 이상 10 이하이다.
배열에서 빙산이 차지하는 칸의 개수, 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다.
배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.
*/

int board[302][302];
int vis[302][302];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vis[i][j] = 0;
        }
    }
}

void melting() {
    int melt[302][302] = { 0 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (board[nx][ny] == 0) melt[i][j]++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[i][j] = board[i][j] - melt[i][j];
            if (board[i][j] < 0) board[i][j] = 0;
        }
    }
}

// 0 : 모든 빙산 녹음, 1: 한덩어리 , 2: 2덩이 이상 분리 성공
int status() {
    int x = -1, y = -1;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j]) {
                x = i;
                y = j;
                cnt++;
            }
        }
    }
    // 모든 칸이 0이므로 다 녹음
    if (cnt == 0) return 0;
    int cnt2 = 0;
    queue <pair<int, int>> Q;
    vis[x][y] = 1;
    Q.push({ x,y });
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        cnt2++;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
            vis[nx][ny] = 1;
            Q.push({ nx,ny });
        }
    }

    //전체 빙산의 칸이 x,y에 붙어있는 빙산의 칸과 일치하면 아직 한 덩어리
    if (cnt == cnt2) return 1;
    // cnt 는 논리상 0이 될수없으므로 cnt2와 다르면 무조건 분리된 상황
    return 2;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    while (1) {
        ans++;
        melting();
        init();
        int check = status();
        if (check == 0) {
            cout << 0;
            return 0;
        }
        else if (check == 1)
            continue;
        else
            break;
    }

    cout << ans;
    return 0;
}
