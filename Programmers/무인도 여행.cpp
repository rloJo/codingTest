#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[102][102] = { 0 };

int find_way(pair<int,int> st, vector<string>&maps) {
    
    int size = 0;
    queue<pair<int, int>> Q;

    Q.push(st);
    vis[st.X][st.Y] = true;

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        size += maps[cur.X][cur.Y] - '0';
        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + cur.X;
            int ny = dy[dir] + cur.Y;
            if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size()) continue;
            if (vis[nx][ny] || maps[nx][ny] == 'X') continue;
            vis[nx][ny] = true;
            Q.push({ nx,ny });
        }
    }

    return size;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'X' || vis[i][j]) continue;
            answer.push_back(find_way({ i,j }, maps));
        }
    }
    if (answer.size() <= 0) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    return answer;

}
