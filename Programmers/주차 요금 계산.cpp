#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

map <int, int> fee; // 차량과 해당하는 차량의 요금 저장
unordered_map<int, int> totaltime; // 해당 차량의 총 이용시간
unordered_map<int, string> inTime;// 들어온 차량의 시간 저장 

void calcTime(string out, string in, int number) {
    int oh = stoi(out.substr(0, out.find(':')));
    int om = stoi(out.substr(out.find(":") + 1));
    int ih = stoi(in.substr(0, in.find(':')));
    int im = stoi(in.substr(in.find(":") + 1));

    if (om < im) {
        om += 60;
        oh--;
    }

    int total = (om - im) + (oh - ih) * 60;
    totaltime[number] += total;
}

void setTime(string record, vector<int>& fees) {
    string time = record.substr(0, record.find(' '));
    record.erase(0, record.find(' ')+1);
    int number = stoi(record.substr(0, record.find(' ')));
    record.erase(0, record.find(' ')+1);
    if (record == "IN") {
        inTime[number] = time;
    }
    if(record =="OUT") {
        calcTime(time, inTime[number], number);
        inTime.erase(number); 
    }
}

void calcFee(int number, vector<int> fees) {
    totaltime[number] -= fees[0];
    fee[number] = fees[1];
    if (totaltime[number] > 0) {
        fee[number] += (totaltime[number] / fees[2]) * fees[3];
        if (totaltime[number] % fees[2] != 0) fee[number] += fees[3];
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {   
    vector<int> answer;
    for (string record : records) setTime(record, fees);

    for (auto intime : inTime) calcTime("23:59", intime.second, intime.first);

    for (auto t : totaltime) calcFee(t.first, fees);

    for (auto f : fee) answer.push_back(f.second);

    return answer;
}
