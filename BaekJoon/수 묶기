#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool hasZero = false;
vector<int> Minus;
vector<int> Plus;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num > 0) Plus.push_back(num);
		else if (num == 0) hasZero = true;
		else Minus.push_back(num);
	}
	sort(Minus.begin(), Minus.end());
	sort(Plus.begin(), Plus.end(), greater<>());
}

void solution() {
	int answer = 0;
	for (int i = 0; i < (int) Plus.size()-1; i += 2) {
		if (Plus[i + 1] == 1) answer += Plus[i] + Plus[i + 1];
		else answer += (Plus[i + 1] * Plus[i]);
	}
	if (Plus.size() % 2) answer += Plus[Plus.size() - 1];

	
	for (int i = 0; i < (int) Minus.size()-1; i += 2) answer += (Minus[i] * Minus[i+1]);
	if (Minus.size() % 2) {
		if(!hasZero)  answer += Minus[Minus.size() - 1];
	}

	cout << answer;
}

int main() {
	init();
	input();
	solution();
}
