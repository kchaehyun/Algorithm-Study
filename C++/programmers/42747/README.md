# Programmers 42747 - H-Index

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42747)
- 어떤 과학자가 발표한 논문의 인용 횟수가 담긴 배열 `citations`가 주어진다.
- H-Index는 발표한 논문 중 `h`번 이상 인용된 논문이 `h`편 이상이고, 나머지 논문이 `h`번 이하 인용되었을 때 가능한 `h`의 최댓값이다.
- 이 과학자의 H-Index를 반환한다.

## 아이디어
- 인용 횟수를 오름차순으로 정렬한다.
- 정렬된 배열에서 `i`번째 논문을 기준으로 보면, `i`부터 끝까지 남은 논문 수는 `n - i`개다.
- `citations[i] >= n - i`라면 현재 논문부터 끝까지의 모든 논문은 최소 `n - i`번 이상 인용된 것이다.
- 오름차순으로 앞에서부터 확인하므로 처음 조건을 만족하는 `n - i`가 가능한 가장 큰 H-Index다.

## 시간복잡도
- 정렬이 지배적이므로 O(N log N)

## 풀이 과정
1. 논문의 개수 `n`을 저장한다.
2. `citations`를 오름차순으로 정렬한다.
3. 배열을 앞에서부터 순회한다.
4. 현재 인용 횟수 `citations[i]`가 남은 논문 수 `n - i` 이상이면 `n - i`를 반환한다.
5. 끝까지 조건을 만족하지 못하면 H-Index는 0이므로 0을 반환한다.

## 코드 설명
```cpp
int solution(vector<int> citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end());
    for(int i = 0 ; i < citations.size() ; ++i) {
        if(citations[i] >= n-i) return n-i;
    }
    return 0;
}
```
- `sort(citations.begin(), citations.end())`로 인용 횟수를 오름차순 정렬한다.
- `n - i`는 현재 위치부터 끝까지 남아 있는 논문의 개수다.
- `citations[i] >= n - i`를 만족하면 `n - i`편 이상의 논문이 각각 `n - i`번 이상 인용된 것이므로 해당 값을 반환한다.
- 조건을 만족하는 위치가 없다면 가능한 H-Index가 없으므로 0을 반환한다.
