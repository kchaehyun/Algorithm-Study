# Programmers 1845 - 폰켓몬

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/1845)
- `nums`에서 정확히 `N/2`마리를 선택할 때, 서로 다른 종류의 수를 최대로 해야 한다.

## 아이디어
- 선택 가능한 최대 마릿수는 `len(nums)//2`다.
- 서로 다른 종류 수는 `len(set(nums))`와 같다.
- 정답은 두 값의 최솟값이다.

## 시간복잡도
- O(N)

## 풀이 과정
1. 딕셔너리로 각 종류의 등장 여부를 기록한다.
2. 전체 종류 수를 계산한다.
3. `N/2`와 종류 수 중 작은 값을 반환한다.

## 코드 설명
```python
def solution(nums):
    answer = 0
    dic = {}
    for n in nums :
        if n not in dic :
            dic[n] = 1
        else :
            dic[n] += 1
    answer = min(len(nums)//2,len(dic))
    return answer
```
- `len(dic)`가 서로 다른 폰켓몬 종류 수다.
- 결국 `선택 가능 수`와 `종류 수` 중 작은 값이 최댓값이 된다.
