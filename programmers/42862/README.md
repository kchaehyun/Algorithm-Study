# Programmers 42862 - 체육복

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42862)
- 체육복을 잃어버린 학생 `lost`, 여벌이 있는 학생 `reserve`가 주어진다.
- 번호가 인접한 학생에게만 체육복을 빌려줄 수 있을 때, 수업을 들을 수 있는 최대 학생 수를 구한다.

## 아이디어
- `lost`와 `reserve`를 집합으로 두면 중복 처리(본인이 잃어버리고 여벌도 가진 경우)가 쉽다.
- 먼저 교집합을 제거해 순수 분실/여벌 학생만 남긴다.
- 분실 학생을 번호순으로 보며 `왼쪽 -> 오른쪽` 순서로 빌린다.

## 시간복잡도
- 정렬 포함 O(L log L)

## 풀이 과정
1. `lost`, `reserve`를 집합으로 변환한다.
2. 교집합을 제거해 자기 체육복만 가진 학생을 정리한다.
3. 정렬된 `lost`를 순회하며 `l-1`, 없으면 `l+1`에서 빌린다.
4. 최종적으로 `n - len(lost)`를 반환한다.

## 코드 설명
```python
def solution(n, lost, reserve):
    lost = set(lost)
    reserve = set(reserve)
    inter = lost & reserve
    lost -= inter
    reserve -= inter
    for l in sorted(lost) :
        if l-1 in reserve :
            reserve.remove(l-1)
            lost.remove(l)
            continue
        elif l+1 in reserve :
            reserve.remove(l+1)
            lost.remove(l)
            continue
            
    return n - len(lost)
```
- 교집합 제거로 예외 케이스를 먼저 처리해 로직이 단순해진다.
- 가까운 번호에서 한 번만 빌려주도록 `reserve.remove`를 사용한다.
