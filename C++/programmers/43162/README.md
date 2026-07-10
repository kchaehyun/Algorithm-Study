# Programmers 43162 - 네트워크

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/43162)
- 컴퓨터의 개수 `n`과 연결 정보를 담은 인접 행렬 `computers`가 주어진다.
- 서로 직접 또는 간접적으로 연결된 컴퓨터들은 하나의 네트워크를 이룬다.
- 전체 컴퓨터들이 몇 개의 네트워크로 나뉘는지 구한다.

## 아이디어
- 연결된 컴퓨터들을 하나의 그룹으로 묶어야 하므로 DFS를 사용한다.
- 아직 방문하지 않은 컴퓨터를 발견하면 새로운 네트워크가 시작된 것이다.
- 해당 컴퓨터에서 DFS를 수행해 같은 네트워크에 속한 모든 컴퓨터를 방문 처리한다.
- DFS가 새로 시작되는 횟수가 네트워크의 개수다.
- 재귀 대신 `stack`을 사용해 반복문으로 DFS를 구현한다.

## 시간복잡도
- 각 컴퓨터에서 인접 행렬의 한 행을 확인하므로 O(N^2)

## 풀이 과정
1. 방문 여부를 저장할 `visited` 배열을 만든다.
2. 0번 컴퓨터부터 `n - 1`번 컴퓨터까지 순회한다.
3. 아직 방문하지 않은 컴퓨터라면 네트워크 개수 `answer`를 1 증가시킨다.
4. 해당 컴퓨터를 시작점으로 DFS를 수행한다.
5. DFS에서는 스택에서 컴퓨터 번호를 하나씩 꺼내며 연결된 미방문 컴퓨터를 찾는다.
6. 연결된 컴퓨터를 방문 처리하고 스택에 넣어 같은 네트워크를 계속 탐색한다.
7. 모든 컴퓨터 순회가 끝나면 `answer`를 반환한다.

## 코드 설명
```cpp
void dfs(int i, vector<vector<int>> computers, vector<bool>& visited) {
    visited[i] = true;
    stack<int> s;
    s.push(i);
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        for(int j = 0 ; j < computers.size() ; ++j) {
            if(computers[cur][j] == 1 && !visited[j]) {
                visited[j] = true;
                s.push(j);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> v(n, false);
    for(int i = 0 ; i < n ; ++i) {
        if(!v[i]) {
            answer++;
            dfs(i, computers, v);
        }
    }
    return answer;
}
```
- `visited`는 각 컴퓨터가 이미 어떤 네트워크에 포함되었는지 기록한다.
- `dfs`는 시작 컴퓨터와 연결된 모든 컴퓨터를 찾아 방문 처리한다.
- `computers[cur][j] == 1`이면 `cur` 컴퓨터와 `j` 컴퓨터가 연결되어 있다는 뜻이다.
- 방문하지 않은 연결 컴퓨터만 스택에 넣어 중복 탐색을 막는다.
- `solution`에서 DFS가 실행될 때마다 새로운 네트워크를 하나 찾은 것이므로 `answer`를 증가시킨다.
