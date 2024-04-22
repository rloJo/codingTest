#include <iostream>
#include <algorithm>
#define L first
#define H second
using namespace std;

int N;
pair<int, int> column[1003];
int ans = 0;
int mx = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> column[i].L >> column[i].H;
		mx = mx < column[i].H ? column[i].H : mx;
	}
	
	if (N == 1) {
		cout << column[0].H;
		return 0;
	}

	sort(column, column + N);
	
	int curl = 0; int heightl = column[0].H;
	int idxl = 0;
	while (column[curl].H != mx) {
		if (column[curl].H > column[idxl].H) {
			ans += (column[curl].L - column[idxl].L) * heightl;
			heightl = column[curl].H;
			idxl = curl;
		}
		curl++;
	}
	ans += (column[curl].L - column[idxl].L) * heightl;

	int curr = N - 1; int heightr = column[N-1].H;
	int idxr = N - 1;
	while (column[curr].H != mx) {
		if (column[curr].H > column[idxr].H) {
			ans += (column[idxr].L - column[curr].L) * heightr;
			heightr = column[curr].H;
			idxr = curr;
		}
		curr--;
	}
	ans += (column[idxr].L - column[curr].L) * heightr;
	//최대값이 한개인 경우
	if (curr == curl) ans += mx;
	//최대값이 여러개인 경우
	else { 
		ans += (column[curr].L - column[curl].L + 1) * mx;
	}

	cout << ans << "\n";
}

