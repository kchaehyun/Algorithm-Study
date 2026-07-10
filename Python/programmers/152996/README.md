# Programmers 152996 - 시소 짝꿍

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/152996)
- 사람들의 몸무게가 담긴 배열 `weights`가 주어진다.
- 시소는 중심으로부터 2m, 3m, 4m 떨어진 위치에 앉을 수 있다.
- 두 사람이 서로 다른 거리 또는 같은 거리에 앉았을 때 토크가 같으면 시소 짝꿍이 된다.
- 만들 수 있는 시소 짝꿍의 수를 반환한다.

## 아이디어
- 같은 몸무게가 여러 명 있을 수 있으므로 `Counter`로 몸무게별 인원 수를 센다.
- 같은 몸무게끼리는 같은 거리에 앉으면 균형을 이룰 수 있다.
- 서로 다른 몸무게는 거리 비율에 따라 `2:3`, `2:4`, `3:4` 관계가 될 때 균형을 이룬다.
- 현재 몸무게 `w`에 대해 `w * 3 / 2`, `w * 2`, `w * 4 / 3`이 존재하는지 확인한다.
- 한쪽 방향으로만 확인해 중복 계산을 피한다.

## 시간복잡도
- 몸무게 종류 수를 M이라고 하면 각 몸무게를 한 번씩 확인하므로 O(M)이다.

## 풀이 과정
1. `Counter(weights)`로 각 몸무게의 등장 횟수를 저장한다.
2. 같은 몸무게가 2명 이상이면 조합 수 `v * (v - 1) // 2`를 더한다.
3. `w * 3 / 2`가 존재하면 `2:3` 거리 비율로 균형을 이루는 쌍을 더한다.
4. `w * 2`가 존재하면 `2:4` 거리 비율로 균형을 이루는 쌍을 더한다.
5. `w * 4 / 3`이 존재하면 `3:4` 거리 비율로 균형을 이루는 쌍을 더한다.
6. 누적한 `answer`를 반환한다.

## 코드 설명
```python
from collections import Counter

def solution(weights):
    answer = 0
    weights = Counter(weights)
    for w,v in weights.items() :
        if v > 1:
            answer += v*(v-1)//2
        if w*3/2 in weights :
            answer += v*weights[w*3/2]
        if w*2 in weights :
            answer += v*weights[w*2]
        if w*4/3 in weights :
            answer += v*weights[w*4/3]
    return answer
```
- `Counter`를 사용해 같은 몸무게의 사람 수를 빠르게 조회한다.
- 같은 몸무게는 `v`명 중 2명을 고르는 경우의 수를 더한다.
- `w * 3 / 2`, `w * 2`, `w * 4 / 3`은 각각 가능한 몸무게 비율을 확인하는 값이다.
- 조건을 만족하는 몸무게가 있으면 두 몸무게 그룹의 인원 수 곱만큼 짝꿍을 만들 수 있다.
