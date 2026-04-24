# BOJ 16918 - 봄버맨

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/16918)
- `R x C` 크기의 격자판에서 봄버맨이 폭탄을 설치하고 터뜨리는 과정을 시뮬레이션한다.
- 폭탄은 설치된 지 3초 후에 폭발하며, 인접한 네 칸도 함께 파괴된다.
- `N`초 후의 격자판 상태를 구한다.

## 아이디어
- 시간에 따른 격자판의 변화 패턴을 파악한다.
  - 1초: 초기 상태 그대로.
  - 짝수 초(2, 4, ...): 모든 칸에 폭탄이 가득 참.
  - 3초, 7초, ... (N % 4 == 3): 초기 폭탄들이 터진 상태.
  - 5초, 9초, ... (N % 4 == 1): 3초 때 설치된 폭탄들이 터진 상태.
- 패턴에 따라 격자판 상태를 계산하는 함수를 작성한다.

## 시간복잡도
- 격자판의 크기가 `R x C`일 때, 상태 변환 한 번에 `O(R * C)`가 소요된다.
- `N`에 따라 최대 두 번의 변환을 수행하므로 전체 시간복잡도는 `O(R * C)`이다.

## 풀이 과정
1. `R, C, N`과 초기 격자판 상태를 입력받는다.
2. `N`이 1이면 초기 상태를 출력한다.
3. `N`이 짝수이면 모든 칸이 폭탄(`O`)인 상태를 출력한다.
4. `N % 4 == 3`이면:
   - 모든 칸에 폭탄을 채운 뒤, 초기 폭탄 위치와 그 인접 칸들을 빈 칸(`.`)으로 바꾼 상태를 출력한다.
5. `N % 4 == 1`이면:
   - 위 과정을 두 번 반복하여 출력한다. (3초 때의 결과에 대해 다시 폭발 시뮬레이션 수행)

## 코드 설명
```python
import sys
input = sys.stdin.readline

R, C, N = map(int, input().split())
graph = [input().strip() for _ in range(R)]

def status(original_graph) :
    result = [['O']*C for _ in range(R)]
    for r in range(R) :
        for c in range(C) :
            if original_graph[r][c] == 'O' :
                result[r][c] = '.'
                for dr,dc in [(1,0),(0,1),(-1,0),(0,-1)] :
                    nr = r + dr
                    nc = c + dc
                    if 0 <= nr < R and 0 <= nc < C :
                        result[nr][nc] = '.'
    return result   

if N == 1 :
    print('\n'.join(graph))
elif N % 2 == 0 :
    print('\n'.join(['O'*C for _ in range(R)]))
elif N % 4 == 3 :
    graph = status(graph)
    for g in graph :
        print(''.join(g))
elif N % 4 == 1 :
    graph = status(status(graph))
    for g in graph :
        print(''.join(g))
```
- `status` 함수는 현재 폭탄들의 위치를 기준으로 폭발 후의 상태를 계산한다.
- `N`이 4의 배수 + 1인 경우(예: 5초)는 3초 때의 상태에서 폭탄이 터진 것이므로 `status`를 중첩 적용한다.
