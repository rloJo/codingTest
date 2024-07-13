#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool cnt[32][32] = { false };

void init_cnt(int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cnt[i][j] = false;
        }
    }
}

int count(int m, int n) {
    int brokenBlock = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (cnt[i][j]) brokenBlock++;
        }
    }
    return brokenBlock;
}

bool find(int m, int n, vector<string>& board) {
    bool isBreak = false;
    init_cnt(m,n);
    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < n - 1; j++) {
            char st = board[i][j]; 
            if (st == '0') continue;
            if (!(board[i + 1][j] == st && board[i][j + 1] == st && board[i + 1][j + 1] == st)) continue;
            cnt[i][j] = true;
            cnt[i + 1][j] = true;
            cnt[i][j + 1] = true;
            cnt[i + 1][j + 1] = true;
            isBreak = true;
        }
    }
    return isBreak;
}

void fall(int m,int n,vector<string>& board) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (cnt[i][j]) board[i][j] = '0';
        }
    }

    for (int i = m-2; i >=0; i--) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '0') continue;
            int x = i; int y = j;
            while (x+1 < m && board[x+1][y] == '0') {
                board[x + 1][y] = board[x][y];
                board[x][y] = '0';
                x++;
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (find(m,n,board)) {
        answer += count(m,n);
        fall(m,n,board);
    }
  
    return answer;
}
