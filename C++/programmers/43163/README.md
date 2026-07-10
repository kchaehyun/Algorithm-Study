# Programmers 43163 - 단어 변환

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/43163)
- 시작 단어 `begin`에서 목표 단어 `target`으로 변환하려고 한다.
- 한 번에 한 글자만 바꿀 수 있고, 바꾼 단어는 `words` 안에 있어야 한다.
- `begin`에서 `target`까지 변환하는 데 필요한 최소 단계를 구한다.
- 변환할 수 없다면 0을 반환한다.

## 아이디어
- 단어를 그래프의 정점으로 생각한다.
- 두 단어가 한 글자만 다르면 한 번의 변환으로 이동할 수 있으므로 간선이 있다고 볼 수 있다.
- 최소 변환 횟수를 구해야 하므로 BFS를 사용한다.
- 큐에는 현재 단어와 지금까지의 변환 횟수를 함께 저장한다.
- `target`이 `words`에 없다면 변환이 불가능하므로 바로 0을 반환한다.

## 시간복잡도
- 각 단어를 방문할 때마다 모든 단어와 비교하고, 비교할 때 단어 길이만큼 확인하므로 O(N^2 * L)
- `N`은 `words`의 길이, `L`은 단어의 길이다.

## 풀이 과정
1. `target`이 `words` 안에 없으면 0을 반환한다.
2. BFS 큐에 시작 단어 `begin`과 변환 횟수 0을 넣는다.
3. 방문 여부를 저장할 `visited` 배열을 만든다.
4. 큐에서 현재 단어와 변환 횟수를 꺼낸다.
5. 현재 단어가 `target`이면 현재 변환 횟수를 반환한다.
6. `words`를 순회하며 아직 방문하지 않았고 한 글자만 다른 단어를 찾는다.
7. 찾은 단어를 방문 처리하고 변환 횟수를 1 증가시켜 큐에 넣는다.
8. BFS를 통해 가장 먼저 `target`에 도달한 횟수가 최소 변환 횟수다.

## 코드 설명
```cpp
bool isChange(const string& cur, const string& target) {
    int diff = 0;
    for(int i = 0 ; i < cur.size() ; ++i) {
        if(cur[i] != target[i]){
            diff++;
            if(diff > 1) return false;
        }
    }
    return true;
}

int bfs(const string& begin, const string& target, const vector<string>& words) {
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    int n = words.size();
    queue<pair<string,int>> q;
    q.push({begin,0});
    vector<bool> visited(n, false);
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(cur.first == target) return cur.second;
        for(int i = 0 ; i < n ; ++i) {
            if(!visited[i] && isChange(cur.first, words[i])) {
                visited[i] = true;
                q.push({words[i],cur.second+1});
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = bfs(begin,target,words);
    return answer;
}
```
- `isChange`는 두 단어의 서로 다른 글자 수를 세어 한 글자만 다른지 확인한다.
- 서로 다른 글자가 2개 이상이면 한 번에 변환할 수 없으므로 `false`를 반환한다.
- `queue<pair<string, int>>`에는 현재 단어와 해당 단어까지 도달하는 데 걸린 변환 횟수를 저장한다.
- `visited`는 같은 단어를 반복해서 탐색하지 않기 위해 사용한다.
- BFS는 가까운 단계부터 탐색하므로 `target`을 처음 만났을 때의 변환 횟수가 정답이다.
