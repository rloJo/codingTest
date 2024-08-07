#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

int N, M;
unordered_set <string> memo;
vector<string> writing;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string keyWord;
		cin >> keyWord;
		memo.insert(keyWord);
	}
	for (int i = 0; i < M; i++) {
		string w;
		cin >> w;
		writing.push_back(w);
	}
}

void deleteMemo(string w) {
	istringstream ss (w);
	string word;
	while (getline(ss, word, ',')) {
		memo.erase(word);
	}
}

void solution() {
	for (int i = 0; i < M; i++) {
		deleteMemo(writing[i]);
		cout << memo.size() << "\n";
	}
}

int main() {
	init();
	input();
	solution();
}
