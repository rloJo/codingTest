#include <queue>
#include <tuple>
#define Cost first
#define Node second
using namespace std;

vector<pair<int,int>> adj[102];
bool vis[102];
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> Q;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int cnt =0;
    for(auto cost : costs){
        adj[cost[0]].push_back({cost[2],cost[1]});
        adj[cost[1]].push_back({cost[2],cost[0]});
    }
    vis[0]=true;
    for(auto next : adj[0])
        Q.push({next.Cost,0,next.Node});
    
    while(cnt < n-1){
        int cost, a,b;
        tie(cost,a,b) = Q.top(); Q.pop();
        if(vis[b]) continue;
        answer+= cost;
        vis[b] =true;
        cnt++;
        for(auto next : adj[b])
        Q.push({next.Cost,b,next.Node});
    }
    return answer;
}
