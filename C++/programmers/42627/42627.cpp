#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Task {
    int time;
    int duration;
    int idx;
};

struct comp {
    bool operator()(Task a, Task b) {
        if(a.duration != b.duration) return a.duration > b.duration;
        if(a.time != b.time) return a.time > b.time;
        return a.idx > b.idx;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<Task, vector<Task>, comp> pq;
    int curTime = 0;
    int jobIdx = 0;
    int times = 0;
    sort(jobs.begin(), jobs.end());
    while(jobIdx < jobs.size() || !pq.empty()) {
        while(jobIdx < jobs.size() && curTime >= jobs[jobIdx][0]) {
            pq.push({jobs[jobIdx][0], jobs[jobIdx][1], jobIdx});
            ++jobIdx;
        }
        if(!pq.empty()) {
            Task curTask = pq.top();
            pq.pop();
            curTime += curTask.duration;
            times += curTime-curTask.time;
        }
        else curTime = jobs[jobIdx][0];
    }
    return times/jobs.size();
}