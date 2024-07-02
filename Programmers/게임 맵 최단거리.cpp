#include<vector>
#include<queue>

#define X first
#define Y second

using namespace std;

int vis[102][102] = { 0 };

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int dfs(vector<vector<int>>&maps) {
    queue<pair<int, int>> Q;
    int n = maps.size();
    int m = maps[0].size();

    vis[0][0] = 1;
    Q.push({ 0,0 });
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] !=0 || maps[nx][ny] == 0) continue;
            if (nx == (n - 1) && ny == (m - 1)) 
                return vis[cur.X][cur.Y] + 1;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({ nx,ny });
        }
    }

    return -1;
}

int solution(vector<vector<int> > maps)
{
    return dfs(maps);
}
