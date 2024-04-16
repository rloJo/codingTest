#include <iostream>

using namespace std;

int N;
int T;
bool btn[102];

void boy(int num) {
	for (int i = num; i <= N; i += num)
		btn[i] = !btn[i];
}

void girl(int num) {
	int curl = num - 1;
	int curr = num + 1;
	while (curl > 0 && curr <= N) {
		if (btn[curl] == btn[curr]) {
			btn[curl] = !btn[curl];
			btn[curr] = !btn[curr];
		}
		else 
			break;
		curr++; curl--;
	}
	btn[num] = !btn[num];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> btn[i];
	cin >> T;
	while (T--) {
		int sex, num;
		cin >> sex >> num;
		if (sex == 1) boy(num);
		else girl(num);
	}

	for (int i = 1; i <= N; i++)
	{
		cout << btn[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
}
