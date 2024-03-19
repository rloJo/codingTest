#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
int A[102][102];

int ans = 0;
int row = 3;
int col = 3;

void transpose() { //행렬 뒤집는 함수
	int mx = max(row, col);
	for (int i = 1; i <= mx; i++)
		for (int j = i + 1; j <= mx; j++)
			swap(A[j][i], A[i][j]);

	swap(row, col);
}

void f_sort(int a[]) {
	vector<pair<int, int>> v;
	int freq[101] = {};
	for(int j=1;j<=col;j++){ //해당 행의 숫자 count
		freq[a[j]]++;
	}

	for (int i = 1; i <= 100; i++)
	{
		if (freq[i] != 0) { // 해당 숫자가 0개가 아니면
			v.push_back({ freq[i],i }); // 개수, 숫자 순서
		}
	}

	sort(v.begin(), v.end());
	int j = 0;
	for (int i = 0; i < v.size(); i++) {
		if (j == 100)break;
		a[++j] = v[i].second; //배열에 삽입
		a[++j] = v[i].first;
	}

	col = max(col, j); // 열 크기 조정
	fill(a + j + 1, a + col + 1, 0); //j부터 제일 끝칸까지 0으로 초기화 (줄어드는 경우 대비)
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c >> k;
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++)
			cin >> A[i][j];
	}

	while (ans <= 100 && A[r][c] != k)
	{
		bool transposed = false;
		if (row < col) {
			transpose();
			transposed = true;
		}
		for (int i = 1; i <= row; i++)
			f_sort(A[i]);
		
		if (transposed)
			transpose();
		ans++;
	}


	if (ans > 100) ans = -1;

	cout << ans << "\n";
	return 0;
}
