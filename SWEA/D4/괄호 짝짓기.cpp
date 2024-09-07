#include <iostream>
#include <string>
#include <stack>

using namespace std;

int length;
string str;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	cin >> length;
	cin >> str;
}

bool check() {
	stack<char> st;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '{' || str[i] == '[' || str[i] == '(' || str[i] == '<') {
			st.push(str[i]);
		}
		else {
			if (st.empty()) return false;

			if (str[i] == '}') {
				if (st.top() != '{') return false;
				else st.pop();
			}
			else if (str[i] == ']') {
				if (st.top() != '[') return false;
				else st.pop();
			}
			else if (str[i] == ')') {
				if (st.top() != '(') return false;
				else st.pop();
			}
			else if (str[i] == '>') {
				if (st.top() != '<') return false;
				else st.pop();
			}
		}
	}

	if (st.empty()) return true;
	return false;
}

void solution() {
	for (int tc = 1; tc <= 10; tc++) {
		input();
		bool result = check();
		cout << "#" << tc << " " << result << "\n";
	}
}

int main() {
	init();
	solution();
	return 0;
}
