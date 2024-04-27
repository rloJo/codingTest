#include <iostream>
#include <algorithm>
using namespace std;

string S, T;
string tmp = "";
bool flag = false;

void DFS(string s, string t) {
	if (s == t) {
		flag = true;
		return;
	}

	if (s.length() >= t.length()) return;
	if (t[t.length() - 1] == 'A') {
		tmp = t;
		tmp.erase(tmp.length() - 1);
		DFS(s, tmp);
	}
	if (t[t.length() - 1] == 'B') {
		tmp = t;
		tmp.erase(tmp.length()-1);
		reverse(tmp.begin(), tmp.end());
		DFS(s, tmp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S >> T;
	DFS(S, T);
	if (flag) cout << 1;
	else cout << 0;
	return 0;
}
