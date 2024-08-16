#include <iostream>
#include <string>

using namespace std;

int N;
string tmp;
string cur, want;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N;
	cin >> cur >> want;
	tmp = cur;
}

void switchPush(int index) {
	if(index!=0)
		cur[index-1] = cur[index - 1] == '0' ? '1' : '0'; 
	cur[index] = cur[index] == '0' ? '1' : '0';
	if(index != N-1)
		cur[index+1] = cur[index +1] == '0' ? '1' : '0';
}

int find() {
	int answer = 0;
	for (int i = 1; i < N; i++) {
		if (cur[i - 1] != want[i - 1]) {
			switchPush(i);
			answer++;
		}
	}
	return answer;
}

void solution() {
	int nonePushZero = find();
	if (cur != want) nonePushZero = -1;
	cur = tmp;
	switchPush(0);
	int pushZero = find();
	pushZero++;
	if (cur != want) pushZero = -1;
	if (pushZero == -1) cout << nonePushZero;
	else if (nonePushZero == -1) cout << pushZero;
	else cout << min(pushZero, nonePushZero);
}

int main() {
	init();
	input();
	solution();
}
