#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>

using namespace std;

int calcTime(string t1, string t2) {
    int h1 = stoi(t1.substr(0,2));
    int h2 = stoi(t2.substr(0,2));
    
    int m1 = stoi(t1.substr(3,2));
    int m2 = stoi(t2.substr(3,2));
    
    if((m2-m1) < 0) return (h2-h1-1)*60 + (60+(m2-m1));
    return (h2-h1)*60 + (m2-m1);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<int,string> parking;
    map<int,int> totalTime;
    int defaultTime = fees[0];
    int defaultFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    string time, carNum, state;
    for(string r : records) {
        stringstream ss(r);
        ss >> time >> carNum >> state;
        int carNumber = stoi(carNum);
        if(state == "IN") parking[carNumber] = time;
        else {
            totalTime[carNumber] += calcTime(parking[carNumber], time);
            parking.erase(carNumber);
        }
    }
    
    for(auto [carNum, time] : parking) {
        totalTime[carNum] += calcTime(time, "23:59");
    }
    
    for(auto [carNum, time] : totalTime) {
        if(time <= defaultTime) answer.push_back(defaultFee);
        else
            answer.push_back(defaultFee + (time - defaultTime + unitTime - 1) / unitTime * unitFee);
    }
    return answer;
}