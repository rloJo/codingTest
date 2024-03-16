#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string atom[1000002];
vector<long long> tmp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> atom[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < atom[i].size() / 2; j++) {
			swap(atom[i][j], atom[i][atom[i].size() - 1 - j]);
		}
		tmp.push_back(stoll(atom[i]));
	}

	sort(tmp.begin() , tmp.end());
	for (int i = 0; i < tmp.size(); i++)
		cout << tmp[i] << "\n";
	

	return 0;
}
