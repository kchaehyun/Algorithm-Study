# BOJ 10817 - 세 수

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/10817)
- 세 정수가 주어졌을 때, 두 번째로 큰 정수를 출력하는 문제.

## 아이디어
- 세 수만 주어지므로 단순 정렬 후 가운데 값을 출력하면 된다.
- 오름차순 정렬 시 `arr[1]`이 두 번째로 큰 값.

## 풀이 과정
1. 세 정수를 입력받아 리스트에 저장.
2. 정렬 수행.
3. 두 번째 원소(`arr[1]`) 출력.

## 코드 설명
```python
import sys

input = sys.stdin.readline
arr = list(map(int, input().split()))
arr.sort()

print(arr[1])
```
- arr.sort() → 오름차순 정렬.

- arr[1] → 세 수 중 두 번째로 큰 수.