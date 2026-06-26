# Programmers 42842 - 카펫

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42842)
- 갈색 격자 수 `brown`, 노란색 격자 수 `yellow`가 주어진다.
- 카펫의 가로, 세로 크기 `[w, h]`를 구한다.

## 아이디어
- 전체 칸 수는 `brown + yellow`다.
- 세로 `h`를 3부터 증가시키며 `w = total // h`를 계산한다.
- 내부 노란 영역 `(w-2)*(h-2)`가 `yellow`와 같아지는 순간 정답이다.

## 시간복잡도
- 약수 탐색: O(total)

## 풀이 과정
1. 전체 칸 `total`을 계산한다.
2. `h`를 3부터 증가시키며 가능한 세로를 탐색한다.
3. 각 경우 `w`를 계산하고 내부 영역이 `yellow`와 같은지 확인한다.
4. 조건을 만족하면 `[w, h]`를 반환한다.

## 코드 설명
```python
def solution(brown, yellow):
    answer = []
    total = brown+yellow
    h = 3
    while True :
        w = total // h
        if (w-2)*(h-2) == yellow :
            answer = [w,h]
            break
        else :
            h += 1
        
    return answer
```
- 테두리 두께가 1이므로 내부 영역은 `(w-2)*(h-2)`로 계산한다.
- 조건을 만족하는 첫 `(w,h)` 조합이 문제의 해답이다.
