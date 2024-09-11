#include <string>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int vis[102][102];
pair<int, int> st;

void set_point(vector<string>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'R') st = { i,j };
        }
    }
}

bool OOB(int x, int y, int rs, int cs) {
    return x < 0 || y < 0 || x >= rs || y >= cs;
}

int bfs(vector<string>& board) {
    queue<pair<int, int>> Q;
    Q.push(st);
    vis[st.X][st.Y] = 1;
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X;
            int ny = cur.Y;
            while (!OOB(nx, ny, (int)board.size(), (int)board[0].size()) && board[nx][ny] != 'D') {
                nx += dx[dir];
                ny += dy[dir];
            }
            nx -= dx[dir]; ny -= dy[dir];
            if (vis[nx][ny] > 0) continue;
            if (board[nx][ny] == 'G') return vis[cur.X][cur.Y];
            Q.push({ nx,ny });
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;

        }
    }

    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    set_point(board);
    answer = bfs(board);
    return answer;
}
