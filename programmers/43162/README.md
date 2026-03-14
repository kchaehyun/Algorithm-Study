# Programmers 43162 - 네트워크

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/43162)
- 컴퓨터 수 `n`과 연결 정보 인접행렬 `computers`가 주어진다.
- 서로 연결된 컴퓨터들의 집합(네트워크) 개수를 구한다.

## 아이디어
- 연결된 노드를 한 번에 방문하기 위해 DFS를 사용한다.
- 방문하지 않은 노드에서 DFS를 시작할 때마다 네트워크 수를 1 증가시킨다.

## 시간복잡도
- O(N^2)

## 풀이 과정
1. `visited` 배열을 준비한다.
2. 각 노드 `i`를 순회한다.
3. 미방문 노드면 DFS를 수행해 같은 네트워크를 모두 방문 처리한다.
4. DFS를 시작한 횟수를 정답으로 반환한다.

## 코드 설명
```python
def solution(n, computers):
    answer = 0
    visited = [False]*n
    def dfs(node) :
        visited[node] = True
        for i in range(n) :
            if not visited[i] and computers[node][i] == 1:
                dfs(i)
                
    for i in range(n) :
        if not visited[i] :
            dfs(i)
            answer += 1
    return answer
```
- 인접행렬을 순회하며 연결된 노드를 재귀적으로 방문한다.
- 새로운 DFS 시작 횟수가 곧 네트워크 개수다.
