# Programmers 42577 - 전화번호 목록

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42577)
- 전화번호가 담긴 배열 `phone_book`이 주어진다.
- 어떤 번호가 다른 번호의 접두어인 경우가 있으면 `false`를 반환한다.
- 접두어 관계가 하나도 없으면 `true`를 반환한다.

## 아이디어
- 전화번호를 문자열 기준으로 정렬하면 접두어 관계가 있는 번호들은 서로 인접하게 된다.
- 따라서 모든 쌍을 비교할 필요 없이, 정렬 후 앞뒤로 붙어 있는 번호만 확인하면 된다.
- 예를 들어 `"119"`와 `"1195524421"`은 정렬 후 가까이 위치하므로 인접 비교로 찾을 수 있다.

## 시간복잡도
- 정렬이 지배적이므로 O(N log N)
- 인접한 번호를 확인하는 과정은 O(N)이다.

## 풀이 과정
1. `phone_book`을 문자열 오름차순으로 정렬한다.
2. 두 번째 번호부터 순회하며 바로 이전 번호와 비교한다.
3. 현재 번호의 앞부분이 이전 번호와 같으면 이전 번호가 현재 번호의 접두어이므로 `false`를 반환한다.
4. 끝까지 접두어 관계를 찾지 못하면 `true`를 반환한다.

## 코드 설명
```cpp
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 1; i < phone_book.size(); ++i) {
        if (phone_book[i].substr(0, phone_book[i - 1].size()) == phone_book[i - 1])
            return false;
    }
    return true;
}
```
- `sort(phone_book.begin(), phone_book.end())`로 전화번호를 사전순으로 정렬한다.
- `phone_book[i].substr(0, phone_book[i - 1].size())`는 현재 번호에서 이전 번호 길이만큼 앞부분을 잘라낸다.
- 잘라낸 문자열이 이전 번호와 같다면 이전 번호가 현재 번호의 접두어라는 뜻이다.
- 접두어가 발견되는 즉시 `false`를 반환하고, 없으면 `true`를 반환한다.
