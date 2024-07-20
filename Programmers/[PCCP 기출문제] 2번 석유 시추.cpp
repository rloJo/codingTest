#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

#define X first 
#define Y second

using namespace std;

vector<int> s;
int vis[502][502] = { 0 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool OOB(int x, int y, int n, int m) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

void init(int n,int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            vis[i][j] = -1;
    }
}

void dfs(vector<vector<int>> &land, int n,int m) {
    queue<pair<int, int>> Q;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] != -1) continue;
            if (land[i][j] == 0) continue;
            int cnt = 0;
            vis[i][j] = idx;
            Q.push({ i,j });
            cnt++;
            while (!Q.empty()) {        
                pair<int, int> cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (OOB(nx, ny, n, m)) continue;
                    if (vis[nx][ny] != -1 || land[nx][ny] == 0) continue;
                    vis[nx][ny] = idx;
                    Q.push({ nx, ny });
                    cnt++;
                }
            }
            s.push_back(cnt);
            idx++;
        }
    }
}

int countMax(int n,int m) {
    int answer = 0;
    for (int i = 0; i < m; i++) {
        int tmp = 0; 
        unordered_set<int> oil;
        for (int j = 0; j < n; j++) {
            if (vis[j][i] == -1) continue;
            oil.insert(vis[j][i]);
        }
        for (auto num : oil) tmp += s[num];
        answer = max(tmp, answer);
    }
    return answer;
}

int solution(vector<vector<int>> land) {
    int n = land.size(); int m = land[0].size();
    init(n, m);
    dfs(land, n, m);

    return countMax(n, m);
}

