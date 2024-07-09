#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> dictionary;

vector<int> solution(string msg) {
    vector<int> answer;
    int index = 1;
    for (char alpha = 'A'; alpha <= 'Z'; alpha++) {
        string tmp = ""; tmp += alpha;
        dictionary[tmp] = index++;
    }

    string temp= "";
    for (int i = 0; i < msg.length(); i++) {
        temp += msg[i];
        if (dictionary[temp] == 0)
        {
            dictionary[temp] = index++;
            temp = temp.substr(0, temp.length() - 1);
            answer.push_back(dictionary[temp]);
            temp = "";
            i--;
        }
    }

    answer.push_back(dictionary[temp]);

    return answer;
}
