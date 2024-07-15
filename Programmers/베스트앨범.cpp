#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> genre_idx;
vector<pair<int,int>> play_cnt; // 듣기한 곡수 , 해당 장르 인덱스
vector <vector<pair<int, int>>> play(102); //[장르인덱스] 듣기수 , 해당곡 번호

bool cmp(pair<int,int>a, pair<int,int> b) {
    if (a.first == b.first) {
      return a.second < b.second;
    }

    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int idx = 0;
    for (int i = 0; i < genres.size(); i++) {
        if (genre_idx.find(genres[i]) == genre_idx.end()) {
            genre_idx[genres[i]] = idx;
            play_cnt.push_back({0,idx++});
        }
        play_cnt[genre_idx[genres[i]]].first += plays[i];
        play[genre_idx[genres[i]]].push_back({ plays[i],i });
    }

    sort(play_cnt.begin(), play_cnt.end(), cmp);

    for (int i = 0; i < play.size(); i++) {
        sort(play[i].begin(), play[i].end(), cmp);
    }

    for (int i = 0; i < play_cnt.size(); i++) {
        answer.push_back(play[play_cnt[i].second][0].second);
        if (play[play_cnt[i].second].size() >= 2)
            answer.push_back(play[play_cnt[i].second][1].second);
    }

    return answer;
}
