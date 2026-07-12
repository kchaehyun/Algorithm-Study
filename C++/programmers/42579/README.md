# Programmers 42579 - 베스트앨범

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42579)
- 노래의 장르 `genres`와 재생 횟수 `plays`가 주어진다.
- 많이 재생된 장르를 먼저 수록한다.
- 장르 안에서는 많이 재생된 노래를 먼저 수록한다.
- 재생 횟수가 같은 노래는 고유 번호가 낮은 노래를 먼저 수록한다.
- 장르별로 최대 두 곡씩 베스트앨범에 넣을 때, 수록할 노래의 고유 번호를 순서대로 반환한다.

## 아이디어
- 장르의 우선순위를 정하려면 장르별 총 재생 횟수를 알아야 한다.
- 각 장르에 속한 노래들은 `(재생 횟수, 고유 번호)` 형태로 따로 저장한다.
- 장르 목록은 총 재생 횟수 기준 내림차순으로 정렬한다.
- 각 장르의 노래 목록은 재생 횟수 기준 내림차순, 재생 횟수가 같으면 고유 번호 기준 오름차순으로 정렬한다.
- 정렬된 장르 순서대로 각 장르에서 최대 두 곡의 고유 번호를 정답에 추가한다.

## 시간복잡도
- 노래 수를 `N`, 장르 수를 `G`라고 하면 장르 정렬은 O(G log G)이다.
- 각 장르의 노래를 정렬하는 전체 비용은 최악의 경우 O(N log N)이다.
- 따라서 전체 시간복잡도는 O(N log N)이다.

## 풀이 과정
1. `unordered_map<string, int>`에 장르별 총 재생 횟수를 저장한다.
2. `unordered_map<string, vector<pair<int, int>>>`에 장르별 노래 목록을 `(재생 횟수, 고유 번호)`로 저장한다.
3. 장르별 총 재생 횟수 정보를 `vector<pair<string, int>>`로 옮긴다.
4. 장르 벡터를 총 재생 횟수 기준 내림차순으로 정렬한다.
5. 정렬된 장르를 순회하며 해당 장르의 노래 목록을 정렬한다.
6. 각 장르에서 첫 번째 노래를 정답에 넣고, 두 곡 이상 있으면 두 번째 노래도 넣는다.
7. 완성된 고유 번호 목록을 반환한다.

## 코드 설명
```cpp
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
```
- `total[genres[i]] += plays[i]`는 장르별 총 재생 횟수를 누적한다.
- `music[genres[i]].push_back({plays[i], i})`는 장르별로 노래의 재생 횟수와 고유 번호를 저장한다.
- `compGenre`는 총 재생 횟수가 많은 장르가 앞에 오도록 정렬한다.
- `compMusic`은 재생 횟수가 많은 노래를 앞에 두고, 재생 횟수가 같으면 고유 번호가 낮은 노래를 앞에 둔다.
- 각 장르의 정렬된 노래 목록에서 최대 두 곡만 `answer`에 추가한다.
