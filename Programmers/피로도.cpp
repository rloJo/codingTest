#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool vis[9] = { 0 };

//k는 현재피로도, dungeons[a][0] 은 a던전 입장 최소 피로도
// dungeons[a][1] 은 a던전 소모 피로도
void dfs(vector<vector<int>>& dungeons, int k, int cnt) {
    if (cnt > answer) answer++;
    for (int i = 0; i < dungeons.size();i++) {
        if (!vis[i] && k >= dungeons[i][0]) {
            vis[i] = true;
            k -= dungeons[i][1];

            dfs(dungeons, k, cnt+1);
            k += dungeons[i][1];
            vis[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons){
    
    dfs(dungeons, k, 0);
    return answer;
}
