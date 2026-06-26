# BOJ 5073 - 삼각형과 세 변

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/5073)
- 세 변의 길이가 주어졌을 때, 삼각형의 종류를 판별하는 문제.
- 삼각형 판별 규칙:
  1. 세 변의 합이 0이면 입력 종료.
  2. 삼각형이 성립하지 않으면 "Invalid".
  3. 세 변이 모두 같으면 "Equilateral".
  4. 두 변만 같으면 "Isosceles".
  5. 모두 다르면 "Scalene".

## 아이디어
- 삼각형 조건: 가장 긴 변 < 나머지 두 변의 합.
- 따라서 입력을 정렬해서 가장 긴 변이 `arr[0]`, 나머지가 `arr[1], arr[2]`가 되도록 처리.
- 조건문을 통해 분류.

## 풀이 과정
1. 무한 루프를 돌며 입력을 받음.
2. 입력받은 세 변을 내림차순 정렬.
3. 세 변의 합이 0이면 종료.
4. 삼각형 불가능 조건 확인: `arr[1] + arr[2] <= arr[0]` → "Invalid".
5. 세 변이 모두 같으면 "Equilateral".
6. 두 변만 같으면 "Isosceles".
7. 모두 다르면 "Scalene".

## 코드 설명
```python
import sys
input = sys.stdin.readline

while True:
    arr = list(map(int, input().split()))
    arr.sort(reverse=True)
    if arr[0] + arr[1] + arr[2] == 0:
        break
    if arr[1] + arr[2] <= arr[0]:
        print("Invalid")
        continue
    if arr[0] == arr[1] == arr[2]:
        print("Equilateral")
    elif arr[0] == arr[1] or arr[1] == arr[2]:
        print("Isosceles")
    else:
        print("Scalene")
```
- arr.sort(reverse=True) → 가장 긴 변이 arr[0]에 오도록 정렬.

- 삼각형 불가능 조건(a+b <= c)을 먼저 체크.

- 이후 조건문으로 삼각형 종류 출력.
