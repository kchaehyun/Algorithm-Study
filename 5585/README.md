# BOJ 5585 - 거스름돈

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/5585)
- 물건 가격을 입력받으면 1000엔 지폐로 지불했을 때의 거스름돈을 계산해야 한다.
- 거스름돈은 **500, 100, 50, 10, 5, 1엔 동전**으로만 줄 수 있다.
- 필요한 동전 개수의 최소값을 출력하는 문제.

## 아이디어
- 그리디 알고리즘: 큰 단위의 동전부터 차례대로 나누어주면 항상 최적해를 구할 수 있다.
- 거스름돈을 큰 단위부터 나누고, 남은 금액을 계속 업데이트하면서 개수를 세면 된다.

## 풀이 과정
1. 입력으로 물건 가격을 받음.
2. `1000 - 가격`으로 거스름돈을 계산.
3. while문으로 거스름돈이 0이 될 때까지 반복:
   - 500, 100, 50, 10, 5, 1 순서대로 확인.
   - 해당 금액 이상이면 나눗셈으로 필요한 동전 개수를 세고, 나머지를 갱신.
4. 최종적으로 동전 개수 출력.

## 코드 설명
```python
import sys
input = sys.stdin.readline

num = int(input())
num = int(1000 - num)
answer = 0

while num > 0:
    if num >= 500:
        answer += num // 500
        num %= 500
    elif num >= 100:
        answer += num // 100
        num %= 100
    elif num >= 50:
        answer += num // 50
        num %= 50
    elif num >= 10:
        answer += num // 10
        num %= 10
    elif num >= 5:
        answer += num // 5
        num %= 5
    else:
        answer += num
        num = 0

print(answer)
```

- 1000 - 입력값 → 거스름돈 계산.

- //와 % 연산을 사용해서 큰 동전부터 차례대로 처리.

- 모든 동전 단위를 if-elif로 순서대로 확인.