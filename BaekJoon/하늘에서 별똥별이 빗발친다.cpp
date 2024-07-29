#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

int N, M, L, K;
int answer = 0;

vector<pair<int, int>> stars;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> M >> L >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		stars.push_back({ x,y });
	}
}

inline bool isSave(pair<int, int> st, pair<int, int> ed) {
	return st.X <= ed.X && st.X + L >= ed.X && st.Y <= ed.Y && st.Y + L >= ed.Y;
}

void solution() {
	for (int i = 0; i < stars.size(); i++) {
		for (int j = 0; j < stars.size(); j++) {
			int saveStar = 0;
			int	x = stars[i].X;
			int y = stars[j].Y;
			for (int k = 0; k < stars.size(); k++) {
				if (isSave({x,y}, stars[k])) saveStar++;
			}
			answer = max(answer, saveStar);
		}
	}

	cout << K-answer << "\n";
}

int main() {
	init();
	input();
	solution();
}
