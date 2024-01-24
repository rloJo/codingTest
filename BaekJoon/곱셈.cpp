#include <iostream>

/*
자연수 A를 B번 곱한 수를 알고 싶다.
단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다.
A, B, C는 모두 2,147,483,647 이하의 자연수이다.

*/

using namespace std;
using ll = long long;

ll recursion(ll A, ll B, ll C) {
	if (B == 1)
		return A % C;
	ll val = recursion(A, B / 2, C);
	// a^n * a^n = a^2n 을 이용한 재귀 풀이법 
	val = val * val % C;
	if (B % 2 == 0) return val; // B가 홀수라면 a를 한번 더 곱해주어야함
	else return val * A % C;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll A, B, C;
	cin >> A >> B >> C;
	cout << recursion(A, B, C);
}
