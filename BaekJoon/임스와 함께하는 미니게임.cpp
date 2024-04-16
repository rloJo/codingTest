#include <iostream>
#include <set>

using namespace std;

int N;
char type;
set<string> player;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> type;
	for (int i = 0; i < N; i++){
		string p;
		cin >> p;
		player.insert(p);
	}
	if (type == 'Y') cout << player.size();
	else if (type == 'F') cout << (int)player.size()/2;
	else cout << (int)player.size() / 3;
}
