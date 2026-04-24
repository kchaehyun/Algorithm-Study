# BOJ 20006 - 랭킹전 대기열

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/20006)
- 게임 매칭 시스템을 구현하는 문제이다.
- 매칭 규칙:
  1. 플레이어가 입장했을 때, 매칭이 가능한 방이 있으면 가장 먼저 생성된 방에 입장한다.
  2. 매칭 가능 조건: 방장의 레벨 기준 `±10` 이내, 방 정원이 차지 않음.
  3. 입장 가능한 방이 없으면 새로운 방을 생성한다. (해당 플레이어가 방장이 됨)
  4. 방이 꽉 차면 게임이 시작된다.
- 최종적으로 모든 방의 상태와 플레이어 정보를 출력한다.

## 아이디어
- 각 방의 기준 레벨을 저장할 리스트 `levels`와 방 안의 플레이어 정보를 저장할 리스트 `rooms`를 관리한다.
- 플레이어가 들어올 때마다 `levels`를 순회하며 입장 조건을 확인한다.
- 입장할 방이 없으면 두 리스트에 새로운 정보를 추가한다.

## 시간복잡도
- 플레이어 수 `p`, 최대 방 정원 `m`에 대해 플레이어 한 명당 방 리스트를 순회하므로 최대 `O(p * (p/m))` 즉 `O(p^2/m)`이다.
- `p`는 최대 300이므로 충분히 효율적이다.

## 풀이 과정
1. 플레이어 수 `p`와 방 정원 `m`을 입력받는다.
2. 첫 번째 플레이어 정보를 입력받아 첫 번째 방을 생성한다.
3. 나머지 `p-1`명의 플레이어에 대해:
   - 현재 생성된 모든 방을 순회한다.
   - 방장의 레벨(`levels[i]`) 기준 `±10` 이내이고, 현재 방 인원(`len(rooms[i])`)이 `m`보다 작으면 해당 방에 추가하고 루프를 탈출한다.
   - 모든 방을 확인했으나 들어갈 곳이 없으면 새 방을 생성한다.
4. 모든 방을 순회하며:
   - 인원이 `m`이면 "Started!", 아니면 "Waiting!"을 출력한다.
   - 플레이어들을 닉네임 기준 사전순으로 정렬하여 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

p, m = map(int, input().split())

levels = []
rooms = []

first, f_nickname = map(str, input().split())
levels.append(int(first))
rooms.append([(first, f_nickname)]) 

for _ in range(p-1) :
    l, n = map(str, input().split())
    l = int(l)
    is_join = False
    for i,level in enumerate(levels) :
        if level-10 <= l <= level+10 and len(rooms[i]) < m :
            rooms[i].append((str(l), n))
            is_join = True
            break
    if not is_join :
        rooms.append([(str(l),n)])
        levels.append(l)

for i in range(len(rooms)) :
    if len(rooms[i]) == m :
        print("Started!")
    else :
        print("Waiting!")
    rooms[i] = sorted(rooms[i], key=lambda x:x[1])
    for r in rooms[i] :
        print(' '.join(r))
```
- `levels[i]`는 `i`번째 방을 생성한 방장의 레벨을 저장하여 입장 조건 판별에 사용한다.
- 각 방의 플레이어 명단은 마지막에 정렬하여 출력해야 함에 유의한다.
