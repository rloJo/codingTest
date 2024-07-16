#include <string>
#include <vector>

using namespace std;

int isBooked[2401] = { 0 };

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int st = 0; int ed = 0;
    for (auto book : book_time) {
        int sh, sm, eh, em;
        sh = stoi(book[0].substr(0, book[0].find(":")));
        sm = stoi(book[0].substr(book[0].find(":") + 1));
        eh = stoi(book[1].substr(0, book[1].find(":")));
        em = stoi(book[1].substr(book[1].find(":") + 1));
        
        em += 9;
        if (em >= 60) {
            em -= 60; eh += 1;
        }
        st = sh * 100 + sm;
        ed = eh * 100 + em;
        if (ed >= 2400) ed = 2359;
        for (int i = st; i <= ed; i++) {
            isBooked[i]++;
        }
    }

    for (int i = 0; i <= 2359; i++) {
        answer = max(isBooked[i], answer);
    }

    return answer;
}
