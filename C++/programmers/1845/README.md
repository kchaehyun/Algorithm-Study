# Programmers 1845 - 폰켓몬

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/1845)
- 폰켓몬 종류 번호가 담긴 배열 `nums`가 주어진다.
- 전체 폰켓몬 수가 `N`마리일 때, 정확히 `N / 2`마리를 선택해야 한다.
- 선택할 수 있는 폰켓몬 종류 수의 최댓값을 반환한다.

## 아이디어
- 선택할 수 있는 마리 수는 항상 `nums.size() / 2`마리다.
- 서로 다른 폰켓몬 종류 수는 중복을 제거하면 구할 수 있다.
- 최대로 고를 수 있는 종류 수는 `선택 가능한 마리 수`와 `전체 종류 수` 중 더 작은 값이다.
- 예를 들어 4마리 중 2마리를 고를 수 있고 종류가 3개라면, 실제로는 2종류까지만 고를 수 있다.

## 시간복잡도
- `nums`를 한 번 순회하며 `unordered_set`에 넣으므로 평균 O(N)

## 풀이 과정
1. 중복 없는 종류를 저장할 `unordered_set<int>`를 만든다.
2. `nums`의 모든 값을 set에 넣어 서로 다른 종류 수를 구한다.
3. 선택 가능한 수 `nums.size() / 2`와 종류 수 `poke.size()`를 비교한다.
4. 둘 중 작은 값을 정답으로 반환한다.

## 코드 설명
```cpp
int solution(vector<int> nums)
{
    unordered_set<int> poke;
    for (int n : nums) poke.insert(n);
    if (nums.size() / 2 > poke.size()) return poke.size();
    return nums.size() / 2;
}
```
- `unordered_set`은 같은 값이 여러 번 들어와도 하나만 저장하므로 폰켓몬의 종류 수를 구할 수 있다.
- `poke.size()`는 전체 폰켓몬 종류 수다.
- `nums.size() / 2`보다 종류 수가 적으면 모든 종류를 선택할 수 있고, 종류 수가 더 많으면 선택 가능한 마리 수만큼만 선택할 수 있다.
