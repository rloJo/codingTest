#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> link;

void set_link(int n, vector<vector<int>>& edge)
{
    link = vector<vector<int>>(n+1);
    int from , to;
    for(int i=0;i<edge.size();i++) {
        from = edge[i][0];
        to = edge[i][1];
        link[from].push_back(to);
        link[to].push_back(from);
    }
}

int bfs(int n){
    int far = 0;
    int cnt = 0;
    vector<int> vis(n+1,0);
    queue<int> Q;
    Q.push(1);
    vis[1] = 1;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(vis[cur] > far) {
            far = vis[cur]; 
            cnt = 1;
        }
        else if(vis[cur]==far) cnt++;
        for(int i=0;i<link[cur].size();i++){
            int next = link[cur][i];
            if(vis[next] > 0) continue;
            Q.push(next);
            vis[next] = vis[cur]+1;
        }
        
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    set_link(n,edge);
    answer = bfs(n);
    return answer;
}
