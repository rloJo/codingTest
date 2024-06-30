#include <string>
#include <vector>
#include <algorithm>

#define hit 1
#define miss 5

using namespace std;

int find_runtime(int& cacheSize, vector<string>& cities) {
    int answer=0;
    vector<string> cache;
    for (int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto it = find(cache.begin(), cache.end(), cities[i]);
        if (it != cache.end()) {
            cache.erase(it);
            cache.push_back(cities[i]);
            answer += hit;
        }
        else {
            cache.push_back(cities[i]);
            answer += miss;
            if (cache.size() > cacheSize)
                cache.erase(cache.begin());
        }
    }
    return answer;
}

int solution(int cacheSize, vector<string> cities) {
    return find_runtime(cacheSize, cities);
}
