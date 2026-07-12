# Programmers 131127 - 할인 행사

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/131127)
- 원하는 제품 목록 `want`, 각 제품의 필요 개수 `number`, 날짜별 할인 제품 `discount`가 주어진다.
- 회원 등록일부터 10일 동안 할인하는 제품을 모두 살 수 있어야 한다.
- 원하는 제품을 정해진 개수만큼 모두 살 수 있는 회원 등록 날짜의 총 개수를 반환한다.

## 아이디어
- 회원 등록 날짜를 하루씩 바꿔 가며 10일 동안의 할인 제품을 확인한다.
- 각 시작 날짜 `i`에 대해 `discount[i]`부터 `discount[i + 9]`까지의 제품 개수를 센다.
- 센 제품 개수가 `want`와 `number`의 조건을 모두 만족하면 가능한 날짜다.
- 하나라도 개수가 다르면 해당 날짜는 불가능하다.

## 시간복잡도
- 할인 날짜 수를 `D`, 원하는 제품 수를 `W`라고 하면 시작 날짜마다 10일치 제품을 센다.
- 각 시작 날짜마다 원하는 제품 목록을 확인하므로 전체 시간복잡도는 O(D * (10 + W))이다.
- 10은 상수이므로 O(D * W)로 볼 수 있다.

## 풀이 과정
1. 가능한 회원 등록 날짜 수를 저장할 `answer`를 0으로 초기화한다.
2. `i + 9 < discount.size()`를 만족하는 모든 시작 날짜 `i`를 순회한다.
3. 현재 시작 날짜부터 10일 동안의 할인 제품 개수를 `unordered_map<string, int>`에 저장한다.
4. `want`를 순회하며 각 제품의 개수가 `number`와 같은지 확인한다.
5. 모든 제품 개수가 일치하면 `answer`를 1 증가시킨다.
6. 모든 시작 날짜를 확인한 뒤 `answer`를 반환한다.

## 코드 설명
```cpp
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i = 0 ; i+9 < discount.size() ; ++i) {
        unordered_map<string, int> product;
        for(int j = i ; j < i+10 ; ++j)
            product[discount[j]]++;

        bool possible = true;
        for(int j = 0 ; j < want.size() ; ++j) {
            if(product[want[j]] != number[j]) {
                possible = false;
                break;
            }
        }

        if(possible) answer++;
    }

    return answer;
}
```
- 바깥쪽 반복문의 `i`는 회원 등록을 시작하는 날짜를 의미한다.
- `i + 9 < discount.size()` 조건으로 10일 구간이 존재하는 시작 날짜만 확인한다.
- `product[discount[j]]++`는 10일 동안 할인하는 제품의 개수를 센다.
- `product[want[j]] != number[j]`이면 원하는 제품을 필요한 개수만큼 살 수 없으므로 불가능한 날짜다.
- `possible`이 끝까지 `true`이면 해당 시작 날짜는 조건을 만족하므로 `answer`를 증가시킨다.
