#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool compGenre(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

bool compMusic(pair<int, int>& a, pair<int, int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> total;
    unordered_map<string, vector<pair<int,int>>> music;
    vector<pair<string, int>> genre;
    vector<string> order;
    for(int i = 0 ; i < genres.size() ; ++i) {
        total[genres[i]] += plays[i];
        music[genres[i]].push_back({plays[i],i});       
    }
    for(auto item : total)
        genre.push_back({item.first, item.second});
    sort(genre.begin(), genre.end(), compGenre);
    
    for(auto g : genre) {
        string genreName = g.first;
        auto& musicList = music[genreName];
        sort(musicList.begin(), musicList.end(), compMusic);
        answer.push_back(musicList[0].second);
        if(musicList.size() >= 2)
            answer.push_back(musicList[1].second);
    }
    return answer;
}