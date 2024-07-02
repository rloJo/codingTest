#include <vector>

using namespace std;

bool vis[202] = { 0 };

void DFS(int cur, int n, vector<vector<int>>& computers) {
   
    vis[cur] = true;

    for (int i = 0; i < n; i++) {
        if (!vis[i] && computers[cur][i] == 1)  DFS(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            DFS(i, n, computers);
            answer++;
        }
    }
    return answer;
}
