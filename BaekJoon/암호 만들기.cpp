#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;

vector<char> alpha;
bool isUsed[20];
int vowelCnt = 0;
int consonantCnt = 0;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char word; cin >> word;
		alpha.push_back(word);
	}
	sort(alpha.begin(), alpha.end());
}

bool isVowel(char word) {
	return word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u';
}

void tracking(int idx, int cnt) {
	if(cnt == L){
		if (vowelCnt >= 1 && consonantCnt >= 2) {
			for (int i = 0; i < C; i++)
				if (isUsed[i]) cout << alpha[i];
			cout << "\n";
		}
		return;
	}

	for (int i = idx+1; i < C; i++) {
		if (isUsed[i]) continue;
		if (isVowel(alpha[i])) vowelCnt++;
		else consonantCnt++;
		isUsed[i] = true;
		tracking(i, cnt + 1); 
		if (isVowel(alpha[i])) vowelCnt--;
		else consonantCnt--;
		isUsed[i] = false;
	}
}

void solution() {
	tracking(-1,0);
}

int main() {
	init();
	input();
	solution();
}
