#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int ARow = arr1.size();
    int ACol = arr1[0].size();
    int BCol = arr2[0].size();

    for (int i = 0; i < ARow; i++) {
        vector<int> arr;
        for (int j = 0; j < BCol; j++) {
            int result = 0;
            for (int k = 0; k < ACol; k++) {
                result += arr1[i][k] * arr2[k][j];
            }
            arr.push_back(result);
        }
        answer.push_back(arr);
    }

    return answer;
}
