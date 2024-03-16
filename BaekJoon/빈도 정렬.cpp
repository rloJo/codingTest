#include <iostream>
#include <vector>
using namespace std;

int N, C;
vector<pair<int,long long>> arr;

void bubble_sort() {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 1; j < arr.size() - i; j++) {
			if (arr[j].first > arr[j-1].first)
				swap(arr[j], arr[j-1]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> C;
	for(int i=0;i<N;i++){
		bool flag = true;
		long long tmp = 0;
		cin >> tmp;

		for (int j = 0; j < arr.size(); j++) {
			if (tmp == arr[j].second) {
				arr[j].first+=1;
				flag = false;
				break;
			}
		}
		if (flag)
			arr.push_back({ 1,tmp });
	}

	bubble_sort();

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 1; j <= arr[i].first; j++) {
			cout << arr[i].second << " ";
		}
	}

	return 0;
}
