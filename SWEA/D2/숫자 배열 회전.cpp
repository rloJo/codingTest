#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int arr[7][7];
    int test_case;
    int T, N;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }

        cout << "#" << test_case << "\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << arr[N - j - 1][i];
            cout << " ";
            for (int j = 0; j < N; j++)
                cout << arr[N - i - 1][N - j - 1];
            cout << " ";
            for (int j = 0; j < N; j++)
                cout << arr[j][N-i-1];
            cout << "\n";

        }
       
    }
    return 0;
}
