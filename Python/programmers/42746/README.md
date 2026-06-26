# Programmers 42746 - 가장 큰 수

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42746)
- 0 또는 양의 정수가 담긴 배열 `numbers`가 주어진다.
- 배열의 수를 이어 붙여 만들 수 있는 가장 큰 수를 문자열로 반환한다.

## 아이디어
- 숫자를 문자열로 바꾼 뒤, 어떤 순서로 배치해야 가장 큰 문자열이 되는지 정렬한다.
- 이 문제의 범위(각 수 0~1000)에서는 `x*3` 값을 기준으로 내림차순 정렬하면 올바른 순서를 만들 수 있다.
- 예: `"3"`과 `"30"` 비교 시 `"333"` vs `"303030"`로 비교되어 `"3"`이 앞에 온다.

## 시간복잡도
- 정렬이 지배적이므로 O(N log N)

## 풀이 과정
1. `numbers`를 문자열 리스트로 변환한다.
2. `key=lambda x: x*3` 기준으로 내림차순 정렬한다.
3. 정렬된 값을 이어 붙인다.
4. `"000"` 같은 케이스 처리를 위해 정수 변환 후 다시 문자열로 바꿔 반환한다.

## 코드 설명
```python
def solution(numbers):
    answer = ''
    numbers = list(map(str, numbers))
    numbers.sort(key = lambda x: x*3, reverse=True)
    answer = int("".join(map(str,numbers)))
    if answer != 0 :
        return str(answer)
    else:
        return "0"
```
- `x*3` 정렬로 두 수의 연결 우선순위를 반영한다.
- `int(...)` 변환으로 앞자리 0을 제거해 `["0","0"]` 같은 입력을 `"0"`으로 처리한다.
