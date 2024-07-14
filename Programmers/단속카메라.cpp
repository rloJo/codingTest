#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end());
    int std = routes[0][1];
    int answer = 1;
    for (int i = 0; i < routes.size(); i++) {
        if (std >= routes[i][0]) {
            std = min(routes[i][1], std);
        }
        else{
            answer++;
            std = routes[i][1];
        }
    }

    return answer;
}
