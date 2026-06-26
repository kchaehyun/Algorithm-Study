# BOJ 1283 - 단축키 지정

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1283)
- 여러 옵션 이름들이 주어질 때, 각 옵션에 대한 단축키를 지정하는 문제이다.
- 단축키 지정 규칙:
  1. 단어의 첫 글자가 단축키로 지정되지 않았다면 첫 글자를 지정한다. (왼쪽 단어부터 우선)
  2. 모든 단어의 첫 글자가 이미 지정되었다면, 왼쪽부터 모든 글자를 확인하며 지정되지 않은 글자를 찾는다.
  3. 지정할 수 있는 글자가 없다면 지정하지 않는다.
- 지정된 단축키는 대소문자를 구분하지 않으며, 출력 시에는 해당 글자를 `[]`로 감싼다.

## 아이디어
- 사용된 단축키를 저장할 `set`을 만든다.
- 각 옵션에 대해 규칙 1(첫 글자 확인)을 먼저 수행하고, 실패하면 규칙 2(모든 글자 확인)를 수행한다.
- 대소문자 구분을 없애기 위해 `upper()`를 사용해 저장하고 비교한다.

## 시간복잡도
- 옵션 개수 `N`에 대해 각 옵션의 글자 수를 `L`이라 하면, 최대 `O(N * L)`이다.
- `N`은 최대 30, `L`도 작으므로 충분히 효율적이다.

## 풀이 과정
1. 옵션 개수 `N`을 입력받는다.
2. 사용 중인 단축키를 저장할 `key` set을 초기화한다.
3. 각 옵션을 공백 기준으로 나누어 단어 리스트 `words`를 만든다.
4. **규칙 1**: 각 단어의 첫 글자(`words[i][0]`)를 순회하며 `key`에 없는지 확인한다.
   - 찾으면 `key`에 추가하고 해당 위치(`word`, `idx`)를 저장한 후 중단한다.
5. 규칙 1에서 찾지 못한 경우 **규칙 2**: 모든 단어의 모든 글자를 순회하며 `key`에 없는지 확인한다.
   - 찾으면 `key`에 추가하고 위치를 저장한 후 중단한다.
6. 단축키가 지정되었다면 해당 단어의 글자를 `[ ]`로 감싸서 수정한다.
7. 수정된 단어들을 공백으로 연결하여 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

N = int(input())

key = set()
for _ in range(N) :
    words = list(map(str, input().strip().split(' ')))

    word = -1
    idx = -1
    
    for i in range(len(words)) :
        if words[i][0].upper() not in key :
            key.add(words[i][0].upper())
            word = i
            idx = 0
            break
    if word == -1:
        for i in range(len(words)) :
            for j in range(len(words[i])) :
                if words[i][j].upper() not in key :
                    key.add(words[i][j].upper())
                    word = i
                    idx = j
                    break
            if word != -1 :
                break
    for i in range(len(words)) :
        if i == word :
            w = words[i]
            words[i] = w[0:idx] + '[' + w[idx:idx+1] + ']' + w[idx+1:]
    print(*words)
```
- `word`와 `idx` 변수를 사용하여 단축키로 지정된 글자의 위치를 기억한다.
- `print(*words)`를 통해 리스트의 요소들을 공백으로 구분하여 출력한다.
