#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T;
int num[9] = { 2,7,6,9,5,1,4,3,8 };
bool vis[9];
bool Xwin = false, Owin = false;
string board;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}


void init_vis() {
	for (int i = 0; i < 9; i++) {
		vis[i] = false;
	}
}

void BT(int idx, int cnt, int score, char player) {
	if (cnt == 3) {
		if (score == 15)
		{
			if (player == 'O') Owin = true;
			if (player == 'X') Xwin = true;
		}
		return;
	}

	for (int i = idx; i < board.size(); i++) {
		if (vis[i]) continue;
		if (board[i] != player) continue;
		vis[i] = true;
		BT(i + 1, cnt + 1, score + num[i], player);
		vis[i] = false;
	}
}

void solution() {
	while (1) {
		board = "";
		int Ocnt = 0, Xcnt = 0;
		Xwin = 0, Owin = 0;
		cin >> board;
		if (board == "end") break;

		for (int i = 0; i < board.size(); i++) {
			if (board[i] == 'O') Ocnt++;
			if (board[i] == 'X') Xcnt++;
		}
		init_vis();
		BT(0,0,0,'O');
		init_vis();
		BT(0,0,0,'X');

		if (Xwin&& !Owin && Xcnt - Ocnt == 1) cout << "valid";
		else if (!Xwin&& Owin && Xcnt == Ocnt) cout << "valid";
		else if (!Xwin&& !Owin && Xcnt == 5 && Ocnt == 4) cout << "valid";
		else cout << "invalid";
		cout << "\n";
	}
}

int main() {
	init();
	solution();
}
