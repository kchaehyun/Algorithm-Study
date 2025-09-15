# BOJ 1436 - 영화감독 숌

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1436)
- 어떤 수에 **666**이 들어가면 그 수를 "종말의 수"라고 한다.
- n번째로 작은 종말의 수를 구하는 문제.

## 아이디어
- 단순 구현 문제.
- 666부터 시작해서 모든 자연수를 확인.
- 문자열로 변환해 `"666"`이 포함되면 카운트를 증가.
- n번째에 도달하면 해당 숫자를 출력.

## 풀이 과정
1. 입력값 n을 받음.
2. `num = 666`부터 시작.
3. while문을 돌며 `num`을 문자열로 변환 → `"666"` 포함 여부 확인.
4. 포함되면 카운트 증가.
5. 카운트가 n에 도달하면 종료 후 출력.

## 코드 설명
```python
import sys
input = sys.stdin.readline

n = int(input())
idx = 0
num = 666

while True:
    if '666' in str(num):
        idx += 1
    if idx == n:
        break
    num += 1

print(num)
```
- num → 666부터 시작

- "666" in str(num) → 문자열에 666 포함 여부 확인

- 카운트가 목표(n)에 도달하면 루프 종료 후 출력