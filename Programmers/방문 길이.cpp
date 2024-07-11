#include <string>
#include <set>
#define X first
#define Y second

using namespace std;

set<pair<int, int>> u;
set<pair<int, int>> d;
set<pair<int, int>> r;
set<pair<int, int>> l;

int solution(string dirs) {
    pair<int, int> start;
    int answer = 0;
    for (int i = 0; i < dirs.length(); i++) {
        if (dirs[i] == 'U') {
            if (start.Y + 1 >= 6) continue;
            start.Y++;
            if (u.find(make_pair(start.X, start.Y)) != u.end()) continue;
            if (d.find(make_pair(start.X, start.Y-1)) != d.end()) continue;
            u.insert(make_pair(start.X, start.Y));
            answer++;
        }
        if (dirs[i] == 'D') {
            if (start.Y - 1 <= -6) continue;
            start.Y--;
            if (d.find(make_pair(start.X, start.Y)) != d.end()) continue;
            if (u.find(make_pair(start.X, start.Y+1)) != u.end()) continue;
            d.insert(make_pair(start.X, start.Y));
            answer++;
        }
        if (dirs[i] == 'R') {   
            if (start.X + 1 >= 6) continue;
            start.X++;
            if (r.find(make_pair(start.X, start.Y)) != r.end()) continue;
            if (l.find(make_pair(start.X-1, start.Y)) != l.end()) continue;
            r.insert(make_pair(start.X, start.Y));
            answer++;
        }

        if (dirs[i] == 'L') {
            if (start.X - 1 <= -6) continue;
            start.X--;
            if (l.find(make_pair(start.X, start.Y)) != l.end()) continue;
            if (r.find(make_pair(start.X+1, start.Y)) != r.end()) continue;
            l.insert(make_pair(start.X, start.Y));
            answer++;
        }
    }            
    return answer;
}
