#include <string>
#include <vector>
#include <cmath>

#define X first 
#define Y second

using namespace std;

bool flag = false;
string answer = "impossible";
string tmp = "";
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
char d[4] = { 'd','l','r','u' };

bool isImpossible(pair<int,int>st,pair<int,int> ed ,int k) {
    int remain = abs(st.X - ed.X) + abs(st.Y - ed.Y);
    if ((k-remain) % 2 || remain > k) return true;
    return false;
}

bool OOB(int x, int y, int n, int m) {
    return x <= 0 || y <= 0 || x > n || y > m;
}

void dfs(int cnt, pair<int,int> cur, int n, int m, pair<int,int> st, pair<int,int> ed ,int k) {
    if (flag) return;
    if (isImpossible(cur, ed, k-cnt)) return;
    if (cnt == k) {
        if (cur.X == ed.X && cur.Y == ed.Y) {
            flag = true;
            answer = tmp;
        }
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (OOB(nx, ny, n, m)) continue;
        tmp += d[dir];
        dfs(cnt + 1, { nx,ny }, n, m, st, ed, k);
        tmp.pop_back();
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
  
    pair<int, int> st = { x, y };
    pair<int, int> ed = { r, c };
    dfs(0, st, n, m, st, ed, k);
    return answer;
}
