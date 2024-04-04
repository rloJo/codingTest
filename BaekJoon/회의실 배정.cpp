#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> meeting[100002];
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> meeting[i].second >> meeting[i].first;
	
	sort(meeting, meeting + N);

	int endT = 0;
	for(int i=0;i<N;i++) {
		if (endT > meeting[i].second) continue;
		ans++;
		endT = meeting[i].first;
	}

	cout << ans;

	return 0;
}
