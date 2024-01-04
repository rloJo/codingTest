#include <iostream>

using namespace std;

int main() {
	int N = 0; int X = 0;
	cin >> N >> X;
	int* A = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		if (A[i] < X)
		{
			cout << A[i] << " ";
		}

	}

	delete[]A;
	return 0;
}
