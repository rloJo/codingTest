#include <string>
#include <vector>

using namespace std;

vector<int> coordinate;
vector<double> integral;
int n;

void findN(int k) {
    int cnt = 0;
    coordinate.push_back(k);
    while (k > 1) {
        if (k % 2) {
            k = k * 3 + 1;
        }
        else {
            k /= 2;
        }
        cnt++;
        coordinate.push_back(k);
    }
    n = cnt;
}

double findIntegral(pair<int,int> ranges) {
    double s = 0.0;
    int us = 0; int ds = 0; int h = 0;
    us = coordinate[ranges.first];
    ds = coordinate[ranges.second];
    h = ranges.second - ranges.first;
    s = (double) (us+ds)*h/2;

    return s;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    double sum = 0;
    findN(k);
    integral.push_back(0);
    for (int i = 0; i < n; i++) {
        sum += findIntegral({i,i+1});
        integral.push_back(sum);
    }
    
    for (int i = 0; i < ranges.size(); i++) {
        double s = 0;
        int st = ranges[i][0];
        int ed = ranges[i][1];
        if (ed <= 0) ed = n + ed;
        if (ed < st)
        {
            answer.push_back(-1);
            continue;
        }
        s = integral[ed] - integral[st];
        answer.push_back(s);
    }
    return answer;
}
