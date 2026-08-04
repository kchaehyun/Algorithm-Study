# Programmers 17677 - 뉴스 클러스터링

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/17677)
- 두 문자열 `str1`, `str2`를 각각 두 글자씩 끊어 다중집합을 만든다.
- 두 글자가 모두 영문자인 경우만 원소로 사용하며, 대소문자는 구분하지 않는다.
- 두 다중집합의 자카드 유사도인 `교집합 크기 / 합집합 크기`를 계산한다.
- 계산한 값에 `65536`을 곱한 뒤 소수점 아래를 버린 값을 반환한다.
- 두 집합이 모두 공집합이면 자카드 유사도를 `1`로 정의하므로 `65536`을 반환한다.

## 아이디어
- 각 문자열을 순회하면서 인접한 두 문자를 소문자로 변환한다.
- 두 문자가 모두 알파벳이면 두 글자 문자열을 만들고 `map<string, int>`에 등장 횟수를 기록한다.
- 다중집합에서 같은 원소의 교집합 개수는 두 등장 횟수의 최솟값이다.
- 같은 원소의 합집합 개수는 두 등장 횟수의 최댓값이다.
- 첫 번째 맵을 순회하며 교집합과 합집합을 계산하고, 두 번째 맵에만 존재하는 원소의 개수를 합집합에 추가한다.

## 시간복잡도
- 문자열의 길이를 각각 `N`, `M`이라 하면 부분 문자열을 만드는 과정은 맵 연산을 포함해 `O(N log N + M log M)`이다.
- 두 맵을 순회하는 과정까지 포함해도 전체 시간복잡도는 `O(N log N + M log M)`이다.

## 풀이 과정
1. `str1`의 인접한 두 문자를 확인한다.
2. 두 문자를 소문자로 바꾸고 모두 영문자인 경우 `a`에 등장 횟수를 저장한다.
3. `str2`도 같은 방식으로 처리하여 `b`에 등장 횟수를 저장한다.
4. `a`의 각 원소에 대해 `min(a[word], b[word])`를 교집합 크기에 더한다.
5. 같은 원소에 대해 `max(a[word], b[word])`를 합집합 크기에 더한다.
6. `b`에만 있는 원소의 등장 횟수를 합집합 크기에 추가한다.
7. 교집합과 합집합이 모두 비어 있으면 `65536`을 반환한다.
8. 그 외에는 `교집합 크기 * 65536 / 합집합 크기`를 반환한다.

## 코드 설명
```cpp
#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    map<string, int> a;
    map<string, int> b;
    for(int i = 0 ; i < str1.size()-1 ; ++i) {
        string s;
        char first = tolower(str1[i]);
        char second = tolower(str1[i+1]);
        if(isalpha(first) && isalpha(second)) {
            s += first;
            s += second;
            a[s]++;
        }
    }
    for(int i = 0 ; i < str2.size()-1 ; ++i) {
        string s;
        char first = tolower(str2[i]);
        char second = tolower(str2[i+1]);
        if(isalpha(first) && isalpha(second)) {
            s += first;
            s += second;
            b[s]++;
        }
    }
    int inter = 0;
    int uni = 0;
    for(auto [word, cnt] : a) {
        inter += min(cnt, b[word]);
        uni += max(cnt, b[word]);
    }
    for(auto [word, cnt] : b) {
        if(a.find(word) == a.end()) uni += cnt;
    }
    if(inter == 0 && uni == 0) return 65536;
    return inter*65536/uni;
}
```
- `a`와 `b`는 각 문자열에서 만든 두 글자 원소와 그 등장 횟수를 저장한다.
- `tolower`를 사용해 대소문자를 구분하지 않도록 변환한다.
- `isalpha`로 두 문자가 모두 영문자인 경우만 다중집합에 포함한다.
- `min(cnt, b[word])`는 해당 원소가 교집합에 포함되는 개수이다.
- `max(cnt, b[word])`는 해당 원소가 합집합에 포함되는 개수이다.
- 정수 나눗셈을 사용하므로 `inter * 65536 / uni`의 소수점 아래는 자동으로 버려진다.
