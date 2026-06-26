# Programmers 389479 - [PCCP 기출문제] 1번 / 서버 증설 횟수

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/389479)
- 시간대별 이용자 수에 맞춰 서버를 증설해야 한다.
- 서버 한 대당 `m`명의 이용자를 수용할 수 있다.
- 이용자가 `m * (현재 서버 수 + 1)` 이상이 되면 추가 서버가 필요하다.
- 증설된 서버는 `k`시간 동안 유지된 후 사라진다.
- 0시부터 23시까지 필요한 총 서버 증설 횟수를 구한다.

## 아이디어
- 24시간을 순회하며 각 시간대마다 필요한 서버 수를 계산한다.
- 현재 가동 중인 서버 수를 유지하기 위해, 서버가 사라지는 시각을 기록해둔다.
- `time` 배열을 사용하여 특정 시각에 반납될 서버의 대수를 저장한다.

## 시간복잡도
- O(24)

## 풀이 과정
1. `time` 배열(크기 24+k+1)을 생성하여 각 시각에 만료되는 서버 수를 저장한다.
2. 현재 가동 중인 서버 수 `now_server`를 0으로 초기화한다.
3. 0시부터 23시까지 반복:
    - 현재 시각에 만료되는 서버가 있다면 `now_server`에서 뺀다.
    - 현재 시각의 이용자 수(`players[i]`)를 수용하기 위해 필요한 서버 수를 구한다: `players[i] // m`.
    - 필요한 총 서버 수와 `now_server`를 비교하여 부족한 만큼 증설한다.
    - 증설된 서버 대수만큼 `answer`를 올리고, `now_server`에 더하며, `i + k` 시각에 만료되도록 `time[i+k]`에 기록한다.
4. 총 증설 횟수를 반환한다.

## 코드 설명
```python
def solution(players, m, k):
    answer = 0
    time = [0] *(24+k+1)
    now_server = 0
    for i in range(24) :
        # 서버 만료 처리
        if time[i] != 0 :
            now_server -= time[i]
        
        # 필요한 서버 대수 판별
        # 현재 서버로 수용 가능한 인원: m * (now_server + 1) 미만
        if players[i] >= m * (now_server + 1) :
            need = players[i] // m - now_server
            answer += need
            now_server += need
            time[i+k] += need # k시간 뒤 만료 기록
            
    return answer
```
- 시뮬레이션 방식으로 매 시간의 상태를 업데이트한다.
- `time` 배열을 활용해 서버의 유효 기간을 효율적으로 관리한다.
