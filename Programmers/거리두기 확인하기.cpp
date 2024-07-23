#include <string>
#include <vector>
#include <queue>

#define X first
#define Y second
using namespace std;

int vis[6][6] = { false };
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool OOB(int x, int y, int n, int m) {
    return x < 0 || y < 0 || x >= n || y >= m;
}

void init_vis() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            vis[i][j] = false;
        }
    }
}

bool bfs(vector<string> &places) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (places[i][j] == 'O' || places[i][j] == 'X') continue;
            init_vis();
            queue<pair<int, int>> Q;
            Q.push({ i,j });
            vis[i][j] = 1;
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                if (vis[cur.X][cur.Y] >= 3) continue;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (OOB(nx, ny,5,5)) continue;
                    if (vis[nx][ny] > 0) continue;
                    if (places[nx][ny] == 'X') continue;
                    if (places[nx][ny] == 'P') return false;
                    Q.push({ nx,ny });
                    vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                }       
            }
        }
    }

    return true;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < 5; i++) {
        answer.push_back(bfs(places[i]));
    }

    return answer;
}

