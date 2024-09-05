#include <iostream>
#include <string>
using namespace std;

string oper;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> oper;
}

void solution() {
	int answer = 0;
	string num = "";
	bool isMinus = false;
	for(int i = 0; i <= oper.size(); i++) {
		if (oper[i] == '+' || oper[i] == '-' || i==oper.size()) {
			if (isMinus) {
				answer -= stoi(num);
				num = "";
			}
			else {
				answer += stoi(num);
				num = "";
			}
		}
		else {
			num += oper[i];
		}
		if (oper[i] == '-') {
			isMinus = true;
		}
	}

	cout << answer << "\n";
}

int main() {
	init();
	input();
	solution();
}
