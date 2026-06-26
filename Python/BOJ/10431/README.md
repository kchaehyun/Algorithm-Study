# BOJ 10431 - 줄세우기

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/10431)
- 20명의 학생이 주어질 때, 키 순서대로 줄을 세우는 문제이다.
- 자기보다 키 큰 학생이 앞에 있으면 그 학생 바로 앞에 선다.
- 이때 학생들이 뒤로 물러나는 총 횟수를 구한다.

## 아이디어
- 삽입 정렬(Insertion Sort)의 과정과 동일하다.
- 새로운 학생이 들어올 때마다 현재 줄에서 자기보다 키가 큰 학생 중 가장 앞에 있는 위치를 찾는다.
- 해당 위치에 삽입하고, 그 뒤에 있던 학생들의 수만큼 물러나는 횟수를 카운트한다.

## 시간복잡도
- 테스트 케이스 `P`개에 대해, 각 케이스마다 20명의 학생을 처리한다.
- 각 학생을 삽입할 때 현재 줄(`최대 20명`)을 순회하므로 `O(P * 20^2)`이다.

## 풀이 과정
1. 테스트 케이스 수 `P`를 입력받는다.
2. 각 테스트 케이스마다 학생들의 키 정보를 리스트로 받는다.
3. 빈 리스트 `line`을 생성하여 학생들을 한 명씩 세운다.
4. 현재 학생 `h`가 들어갈 위치 `pos`를 찾는다. `line`의 앞에서부터 순회하며 `h`보다 큰 학생이 처음 나오는 인덱스를 찾는다.
5. `cnt`에 `len(line) - pos`를 더한다 (뒤로 물러나는 학생들의 수).
6. `line.insert(pos, h)`로 학생을 줄에 세운다.
7. 최종적으로 테스트 케이스 번호와 `cnt`를 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

P = int(input())

for _ in range(P) :
    nums = list(map(int, input().split()))
    T = nums[0]
    heights = nums[1:]

    cnt = 0
    line = []
    
    for h in heights :
        pos = len(line)
        for i in range(len(line)) :
            if line[i] > h :
                pos = i
                break
        cnt += len(line) - pos
        line.insert(pos, h)

    print(T, cnt)
```
- `line` 리스트를 통해 현재까지 줄을 선 학생들을 관리한다.
- `pos`는 기본적으로 `len(line)`으로 설정하여, 아무도 자기보다 크지 않으면 맨 뒤에 서도록 한다.
- `line[i] > h`인 경우를 발견하면 그 자리가 `pos`가 되고, 삽입 시 그 뒤 학생들은 한 칸씩 밀리므로 `len(line) - pos`만큼 `cnt`를 증가시킨다.
