#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<vector<int>> link;

void set_link(int n, vector<vector<int>>& wires) {
    link = vector<vector<int>>(n + 1);
    int from, to;
    for (int i = 0; i < wires.size(); i++) {
        from = wires[i][0];
        to = wires[i][1];
        link[from].push_back(to);
        link[to].push_back(from);
    }
}

int bfs(int n, vector<vector<int>>& wires) {
    int diff = 10000;
    int temp = 0;
    int cnt = 0;
    bool vis[102];
    for (int i = 0; i < wires.size(); i++) {
        memset(vis, false, sizeof(vis));
        queue <int> Q;
        int cutNode1 = wires[i][0];
        int cutNode2 = wires[i][1];
        for (int node = 1; node <= n; node++) {
            if (vis[node]) continue;
            temp = cnt;
            Q.push(node);
            vis[node] = true;
            cnt = 1;
            while (!Q.empty()) {
                int cur = Q.front(); Q.pop();
                for (int j = 0; j < link[cur].size(); j++) {
                    int next = link[cur][j];
                    if (vis[next]) continue;
                    if ((cur == cutNode1 && next == cutNode2) || (cur == cutNode2 && next == cutNode1)) continue;
                    Q.push(next);
                    vis[next] = true;
                    cnt++;
                }
            }
        }
        diff = min(diff, abs(temp - cnt));
    }
    return diff;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    set_link(n, wires);
    answer = bfs(n, wires);
    return answer;
}
