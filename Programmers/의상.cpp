#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int cnt_Cloths_Combi(vector<vector<string>>& clothes) {
    unordered_map <string, int> kindOfClothes;
    int answer = 1;
    for (int i = 0; i < clothes.size(); i++) {
            kindOfClothes[clothes[i][1]] ++;
    }

    for (auto iter = kindOfClothes.begin(); iter != kindOfClothes.end(); iter++) {
        answer *= iter->second+1;
    }

    return answer - 1;
}

int solution(vector<vector<string>> clothes) {
    return cnt_Cloths_Combi(clothes);
}
