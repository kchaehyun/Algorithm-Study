# Programmers 42883 - 큰 수 만들기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42883)
- 숫자 문자열 `number`에서 정확히 `k`개를 제거해 만들 수 있는 가장 큰 수를 구한다.

## 아이디어
- 앞자리 숫자가 클수록 전체 값이 커지므로 단조 스택을 사용한다.
- 현재 숫자가 스택 top보다 크면, 제거 가능 횟수(`k`)가 남아있는 동안 작은 숫자를 pop한다.
- 순회 후에도 `k`가 남으면 뒤에서 제거한다.

## 시간복잡도
- O(N)

## 풀이 과정
1. 스택에 첫 숫자를 넣고 시작한다.
2. 다음 숫자를 보며 스택 top보다 크면 `k`를 줄이며 pop한다.
3. 현재 숫자를 스택에 push한다.
4. 순회 후 `k`가 남아 있으면 뒤에서 `k`개를 제외해 반환한다.

## 코드 설명
```python
def solution(number, k):
    stack = [number[0]]
    for n in number[1:] :
        while stack and k > 0 and stack[-1] < n :
            stack.pop()
            k -= 1
        stack.append(n)
    
    if k != 0 :
        return ''.join(map(str,stack[:-k]))
        
    return ''.join(map(str,stack))
```
- 스택은 "현재까지 만들 수 있는 가장 큰 앞자리"를 유지한다.
- 남은 제거 횟수는 뒤자리 제거로 처리한다.
