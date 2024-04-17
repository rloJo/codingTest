#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map <string, int> word;
int N, M;

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		if (a.first.length() == b.first.length())
			return a.first < b.first;
		return a.first.length() > b.first.length();
	}
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string w;
		cin >> w;
		if (w.length() >= M) word[w]++;
	}  

	vector<pair<string, int>> v(word.begin(),word.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << "\n";
}

/*
						map												unordered_map 
정렬			key 기준으로 오름차순 자동정렬											x
중복 허용    중복을 허용하지 않는다(key 있으면값이 삽입 안됨)					허용 x
기반                 red-black tree                                         hash table
탐색 속도              O(N)                                                   O(1)
*/
