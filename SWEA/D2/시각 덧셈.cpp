#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    int H1, H2, M1, M2;
    int aH, aM;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        aH = 0;
        cin >> H1 >> M1 >> H2 >> M2;
        aM = M1 + M2;
        if (aM >= 60) {
            aH++;
            aM -= 60;
        }
        aH += H1 + H2;
        if (aH > 12)
            aH -= 12;
        cout << "#" << test_case << " " << aH << " " << aM << "\n";
    }
    return 0;
}

// 12시간제 
//시간이 1~12로만 나와야한다 조금 이상한 문제
