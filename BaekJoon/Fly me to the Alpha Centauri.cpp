#include <iostream>
#include <cmath>
using namespace std;

int  T;
long long x, y;

int main() {
	cin >> T;
	while (T--) {
		double distance;
		double dist;
		cin >> x >> y;
		distance = y - x;
		dist = sqrt(distance);
		int rdist = round(dist);
		if (dist <= rdist) cout << 2 * rdist  - 1;
		else cout << 2 * rdist;
		cout << "\n";
	}
}

/* 규칙을 찾는 문제
거리      이동 방법      이동 횟수  제곱근    반올림 값
1			1			1			1          1
2		   1 1			2			1.4        1
3		  1 1 1			3			1.7        2
4         1 2 1			3			2          2
5        1 2 1 1		4			2.2        2
6        1 2 2 1		4			2.4        2
7       1 2 2 1 1		5			2.6        3
8       1 2 2 2 1		5			2.8        3
9       1 2 3 2 1		5			3          3
10     1 2 3 2 1 1		6			3.1		   3

각 거리의 제곱근이 > 제곱근의 반올림 값일 경우 2 * 반올림 값
각 거리의 제곱근이 <= 반올림 값일 경우 2*반올림 -1
*/
