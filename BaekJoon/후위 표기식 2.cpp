#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int N;
string oper;
int val[26];
stack<double> calc;
double answer;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> N;
	cin >> oper;
	for (int i = 0; i < N; i++) cin >> val[i];
}

void solution() {
	for (int i = 0; i < oper.size(); i++) {
		if (oper[i] >= 'A' && oper[i] <= 'Z') calc.push(val[oper[i] - 'A']);
		else {
			double op2 = calc.top(); calc.pop();
			double op1 = calc.top(); calc.pop();
			switch (oper[i])
			{
			case '+': calc.push(op1 + op2); break;
			case '-': calc.push(op1 - op2); break;
			case '*': calc.push(op1 * op2); break;
			case '/': calc.push(op1 / op2); break;
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << calc.top();
}

int main() {
	init();
	input();
	solution();
}
