#include <iostream>
#include<tuple>
#include<queue>
#define Cost first
#define Node second

using namespace std;

int N;
bool vis[310];
vector<pair<int, int>> adj[310];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>Q;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void input() {
    int cost;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> cost;
        adj[N+1].push_back({ cost,i });
        adj[i].push_back({ cost,N+1 });
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> cost;
            if (i == j) continue;
            adj[i].push_back({ cost,j });
        }
    }
}

void solution(){
    int answer = 0;
    int cnt = 0;
    for (auto next : adj[1]) Q.push({next.Cost,1,next.Node});
    vis[1] = true;
    N++;
    while (cnt < N-1) {
        int cost, a,b;
        tie(cost,a,b) = Q.top(); Q.pop();
        if (vis[b]) continue;
        vis[b] = true;
        answer += cost;
        cnt++;
        for (auto next : adj[b]) Q.push({next.Cost,b,next.Node});
    }
    cout << answer;
}

int main() {
    init();
    input();
    solution();
}
