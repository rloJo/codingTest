#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> hash;
    for (int i = 0; i < phone_book.size(); i++)
    {
        hash.insert(phone_book[i]);
    }

    for (int i = 0; i < phone_book.size(); i++) {
        string head = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            head += phone_book[i][j];
            if (hash.find(head) !=hash.end() && head != phone_book[i])
                return false;
        }
    }
    
    return true;
}
