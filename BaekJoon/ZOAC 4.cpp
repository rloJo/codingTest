#include <iostream>

using namespace std;

int W, H;
int N, M;
int row,col;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> H >> W >> N >> M;
	for (int i = 1; i <= W; i += (M + 1))
		row++;
	for (int i = 1; i <= H; i += (N + 1))
		col++;

	cout << row * col;

}
