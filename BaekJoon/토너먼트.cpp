#include <iostream>
#include <cmath>

using namespace std;

int N;
double A, B;
int ans = 0;

int main() {
	cin >> N >> A >> B;

	//해당 수를 2로 나누어서 반올림 한 값이 다음 라운드의 번호
	//A와 B는 무조건 경기를 이김. 따라서 번호 수정
	//둘이 연속되는 번호일 때 까지
	do {
		A = round(A / 2);
		B = round(B / 2);
		ans++;
	} while (A != B);

	cout << ans;
}
