# Programmers 82612 - 부족한 금액 계산하기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/82612)
- 놀이기구의 원래 이용료는 `price`원이다.
- 놀이기구를 `n`번째 이용하면 원래 이용료의 `n`배를 받는다.
- 놀이기구를 `count`번 탔을 때, 현재 자신이 가지고 있는 금액에서 얼마가 부족한지 구한다.
- 금액이 부족하지 않으면 0을 반환한다.

## 아이디어
- 총 필요한 금액은 등차수열의 합이다: `price * (1 + 2 + ... + count)`.
- 루프를 돌며 합산하거나 가우스의 덧셈 공식을 사용할 수 있다.

## 시간복잡도
- O(count) 또는 O(1).

## 풀이 과정
1. 1부터 `count`까지 반복하며 `price * i`를 총액에 더한다.
2. 총액에서 가진 돈(`money`)을 뺀 값을 구한다.
3. 부족한 금액이 양수이면 그 값을, 아니면 0을 반환한다.

## 코드 설명
```python
def solution(price, money, count):
    answer = 0
    for i in range(count) :
        answer += price*(i+1)
    
    if answer > money :
        return answer - money
    else :
        return 0
```
- 반복문을 통해 간단하게 총 이용료를 계산한다.
- 최종적으로 소지 금액과 비교하여 결과값을 산출한다.
