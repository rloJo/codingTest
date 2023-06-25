#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int index = 0;
    int T, N;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        index = 0;
        cin >> N;
        vector<pair<char, int>> ans(N);
        for (int i = 0; i < N; i++) {
            cin >> ans[i].first >> ans[i].second;
        }

        cout << "#" << test_case << "\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < ans[i].second; j++) {
                cout << ans[i].first;
                index++;
                if (index % 10 == 0)
                    cout << "\n";
            }
        }
        index = 0;
        cout << "\n";
    }
    return 0;
}
