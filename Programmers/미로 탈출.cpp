#include <string>
#include <vector>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int vis[102][102] = { 0 };

int find_way(pair<int, int> st, pair<int, int> ed, vector<string>&maps) {
   
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            vis[i][j] = 0;
        }
    }

    queue<pair<int, int>> Q;
    Q.push(st);
    vis[st.X][st.Y] = 1;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + cur.X;
            int ny = dy[dir] + cur.Y;
            if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size()) continue;
            if (vis[nx][ny] > 0|| maps[nx][ny] == 'X') continue;
            if (nx == ed.X && ny == ed.Y) return vis[cur.X][cur.Y];
            vis[nx][ny] = vis[cur.X][cur.Y]+ 1;
            Q.push({ nx,ny });
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0; int time = 0;
    pair<int, int > Start;
    pair<int, int> End;
    pair <int, int> Lever;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'S') Start = { i,j };
            if (maps[i][j] == 'L') Lever = { i,j };
            if (maps[i][j] == 'E') End = { i,j };
        }
    }

    time = find_way(Start, Lever, maps);
    if (time == -1) return -1;
    answer += time;
    time = find_way(Lever, End, maps);
    if (time == -1) return -1;
    return answer + time;

}
