# BOJ 1010 - 다리 놓기

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1010)
- 서쪽과 동쪽을 잇는 다리를 놓으려고 한다. 서쪽에는 N개의 사이트가 있고, 동쪽에는 M개의 사이트가 있다. (N ≤ M) 다리는 겹칠 수 없으며, 서쪽의 사이트 개수만큼인 N개의 다리를 놓으려고 할 때, 다리를 놓을 수 있는 경우의 수를 구하는 문제이다.

## 아이디어
- 다리가 서로 겹치지 않으려면, 서쪽의 i번째 사이트는 동쪽의 i번째 사이트보다 왼쪽에 있는 사이트와 연결될 수 없다.
- 결과적으로, 이 문제는 동쪽 사이트 M개 중에서 N개를 순서에 상관없이 선택하는 조합(Combination) 문제와 같다.
- 즉, M개 중 N개를 뽑는 경우의 수 `M C N`을 계산하면 된다.

## 풀이 과정
1. 조합 공식에 필요한 팩토리얼을 계산하는 `factorial` 함수를 정의한다.
2. 테스트 케이스의 개수 T를 입력받는다.
3. T만큼 반복문을 실행하며, 각 테스트 케이스마다 N과 M을 입력받는다.
4. `factorial` 함수를 이용하여 조합 공식 `M! / (N! * (M-N)!)`을 계산한다.
5. 최종 계산된 경우의 수를 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

def factorial(num) :
    idx = 1
    fac = 1
    while idx < num:
        fac *= (idx+1)
        idx += 1
    return fac

T = int(input())

for i in range(T):
    N, M = map(int, input().split())
    print(factorial(M)//(factorial(N) * factorial(M-N)))
```
- 이 문제는 동쪽 사이트 M개 중에서 N개를 선택하는 조합(Combination) 문제와 동일하다.
- `factorial` 함수를 정의하여 팩토리얼을 계산한다.
- 테스트 케이스(T)만큼 반복하면서, 각 케이스마다 N과 M을 입력받는다.
- 조합 공식 `M! / (N! * (M-N)!)`을 사용하여 경우의 수를 계산하고 출력한다.
