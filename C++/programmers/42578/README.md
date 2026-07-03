# Programmers 42578 - 의상

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42578)
- 의상 정보 `clothes`가 주어진다.
- 각 의상은 `[의상 이름, 의상 종류]` 형태다.
- 같은 종류의 의상은 하루에 하나만 입을 수 있다.
- 최소 한 개 이상의 의상을 입을 때, 서로 다른 옷 조합의 수를 반환한다.

## 아이디어
- 의상 이름 자체보다 의상 종류별 개수가 중요하다.
- 어떤 종류에 의상이 `n`개 있다면 선택지는 `n개 중 하나를 입는 경우`와 `아무것도 입지 않는 경우`를 합쳐 `n + 1`개다.
- 모든 종류의 선택지를 곱하면 전체 조합 수가 된다.
- 단, 아무 의상도 입지 않는 경우는 제외해야 하므로 마지막에 1을 뺀다.

## 시간복잡도
- `clothes`를 한 번 순회하며 종류별 개수를 세므로 O(N)

## 풀이 과정
1. `unordered_map<string, int>`에 의상 종류별 개수를 저장한다.
2. `clothes`를 순회하며 `clothes[i][1]`에 해당하는 종류의 개수를 1씩 증가시킨다.
3. 각 종류마다 `개수 + 1`을 정답에 곱한다.
4. 모든 종류에서 아무것도 선택하지 않는 한 가지 경우를 제외하기 위해 1을 뺀다.

## 코드 설명
```cpp
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clo;

    for (auto c : clothes) {
        clo[c[1]]++;
    }

    for (auto c : clo) {
        answer *= (c.second + 1);
    }

    return answer - 1;
}
```
- `clo[c[1]]++`는 의상 종류별 개수를 센다.
- `c.second + 1`에서 `+1`은 해당 종류의 의상을 입지 않는 경우를 의미한다.
- 마지막 `answer - 1`은 모든 종류에서 아무것도 입지 않는 경우를 제거하는 처리다.
