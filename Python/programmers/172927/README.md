# Programmers 172927 - 광물 캐기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/172927)
- 곡괭이 개수 `picks`와 광물 순서 `minerals`가 주어진다.
- 곡괭이는 다이아몬드, 철, 돌 곡괭이 순서로 주어진다.
- 곡괭이 하나는 최대 5개의 광물을 캘 수 있다.
- 광물은 주어진 순서대로만 캘 수 있고, 사용할 수 있는 곡괭이로 피로도의 합을 최소화해야 한다.

## 아이디어
- 곡괭이 하나가 최대 5개를 캐므로 광물을 5개씩 구간으로 나눈다.
- 가진 곡괭이로 캘 수 없는 뒤쪽 광물은 고려하지 않는다.
- 각 구간의 다이아몬드, 철, 돌 개수를 센다.
- 힘든 구간일수록 좋은 곡괭이를 먼저 써야 하므로 광물 개수 튜플을 내림차순 정렬한다.
- 정렬된 구간에 다이아몬드 곡괭이, 철 곡괭이, 돌 곡괭이 순서로 배정한다.

## 시간복잡도
- 광물을 5개씩 나눈 구간 수를 M이라고 하면 정렬 때문에 O(M log M)이다.

## 풀이 과정
1. 전체 곡괭이 수로 캘 수 있는 광물까지만 `minerals`를 자른다.
2. 광물을 5개씩 나누어 각 구간의 광물 개수를 센다.
3. `(diamond, iron, stone)` 형태로 구간 정보를 저장한다.
4. 구간을 내림차순 정렬해 어려운 구간이 앞에 오도록 한다.
5. 남은 곡괭이 중 가장 좋은 곡괭이를 현재 구간에 사용한다.
6. 곡괭이 종류별 피로도 표를 이용해 피로도를 더한다.
7. 모든 구간을 처리한 뒤 `answer`를 반환한다.

## 코드 설명
```python
def solution(picks, minerals):
    answer = 0
    power = [[1,1,1],[5,1,1],[25,5,1]]
    minerals = minerals[:sum(picks)*5]
    
    cnts = []
    for i in range(0, len(minerals), 5) :
        region = minerals[i:i+5]
        d = region.count("diamond")
        iron = region.count("iron")
        s = region.count("stone")
        cnts.append((d,iron,s))
    cnts.sort(reverse=True)
    
    for d,i,s in cnts :
        if picks[0] != 0 :
            picks[0] -= 1
            answer += d*power[0][0]+i*power[0][1]+s*power[0][2]
        elif picks[1] != 0 :
            picks[1] -= 1
            answer += d*power[1][0]+i*power[1][1]+s*power[1][2]
        elif picks[2] != 0 :
            picks[2] -= 1
            answer += d*power[2][0]+i*power[2][1]+s*power[2][2]
    return answer
```
- `power`는 곡괭이 종류별로 다이아몬드, 철, 돌을 캘 때 드는 피로도를 나타낸다.
- `minerals[:sum(picks)*5]`로 실제로 캘 수 있는 광물만 남긴다.
- `cnts.sort(reverse=True)`로 다이아몬드와 철이 많은 구간을 앞에 배치한다.
- 좋은 곡괭이부터 사용해 어려운 구간의 피로도를 줄인다.
