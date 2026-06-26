# BOJ 1302 - 베스트셀러

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1302)
- 오늘 하루 동안 팔린 책의 제목들이 주어졌을 때, 가장 많이 팔린 책의 제목을 출력하는 문제이다.
- 가장 많이 팔린 책이 여러 개일 경우, 사전 순으로 가장 앞서는 제목을 출력한다.

## 아이디어
- 책 제목을 키(Key)로, 팔린 횟수를 값(Value)으로 하는 딕셔너리를 사용하여 각 책의 판매량을 카운트한다.
- 딕셔너리의 값들 중 최댓값(`max_cnt`)을 찾는다.
- 판매량이 `max_cnt`와 일치하는 책 제목들을 리스트에 담고, 이를 정렬하여 가장 첫 번째 요소를 출력한다.

## 시간복잡도
- 모든 책 제목을 순회하며 딕셔너리에 저장하는 데 `O(N)`이 소요된다. (N: 팔린 책의 개수)
- 최댓값을 찾고 필터링하는 데 `O(M)` (M: 고유한 책 제목의 수), 정렬하는 데 `O(M log M)`이 소요된다.
- 전체 시간복잡도는 `O(N + M log M)`이다.

## 풀이 과정
1. 팔린 책의 개수 `N`을 입력받는다.
2. `books` 딕셔너리에 각 책의 제목을 입력받으며 카운트한다.
3. `max(books.values())`를 통해 가장 많이 팔린 횟수를 구한다.
4. 판매량이 최댓값인 책 제목들만 추출하여 `tmp` 리스트에 저장한다.
5. `tmp`를 정렬한 후 첫 번째 요소를 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

N = int(input())
books = {}
for i in range(N) :
    book = input().strip()
    if book not in books :
        books[book] = 1
    else :
        books[book] += 1

max_cnt = max(books.values())
tmp = []
for k,v in books.items() :
    if v == max_cnt :
        tmp.append(k)
print(sorted(tmp)[0])
```
- `sys.stdin.readline`을 사용하여 입력 속도를 높였다.
- `books` 딕셔너리를 이용해 효율적으로 빈도수를 계산했다.
- `sorted(tmp)[0]`을 통해 동률일 경우 사전 순으로 가장 앞선 제목을 선택했다.
