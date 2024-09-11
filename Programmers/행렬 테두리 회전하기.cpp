#include <string>
#include <vector>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int matrix[102][102];

void set_matrix(int rows, int cols){
    int num = 1;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            matrix[i][j] = num++;
}

int turn_matrix(vector<int> &query){
    int minNum = 100000;
    int x = query[0]-1;
    int y = query[1]-1;
    int prev = matrix[x][y];
    int next;
    int dir =0;
    do{
        if(dir == 0 || dir == 2){
            for(int i=query[1]; i<query[3];i++){
                x+= dx[dir];
                y+= dy[dir];
                next = matrix[x][y];
                matrix[x][y] = prev;
                prev = next;
                minNum= min(prev,minNum);
            }
            dir++;
        }
        else if(dir == 1 || dir == 3){
              for(int i=query[0]; i<query[2];i++){
                x+= dx[dir];
                y+= dy[dir];
                next = matrix[x][y];
                matrix[x][y] = prev;
                prev = next;
                minNum= min(prev,minNum);
            }
            dir++;
        }               
    }while(dir<=3);
    return minNum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    set_matrix(rows,columns);
    for(auto query : queries)
        answer.push_back(turn_matrix(query));
    
    return answer;
}
