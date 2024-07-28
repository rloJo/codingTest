#include <iostream>


using namespace std;

int N, K;
int arr[200002];
int cnt[100002];

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

}

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> arr[i];
}

void solution() {
	int answer = 0;
	int Lcur = 1, Rcur = 1;
	while (Rcur <= N) {
	
		if(cnt[arr[Rcur]] >= K){
			while (cnt[arr[Rcur]] >= K) {
				cnt[arr[Lcur]]--;
				Lcur++;
			}
		}

		cnt[arr[Rcur]]++;
		Rcur++;
		answer = max(answer, Rcur - Lcur);
	}

	cout << answer << "\n";
}

int main() {
	init();
	input();
	solution();
}
