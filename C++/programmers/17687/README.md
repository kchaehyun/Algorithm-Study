# Programmers 17687 - n진수 게임

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/17687)
- 숫자를 `0`부터 차례대로 말하되, 각 숫자를 `n`진법으로 변환한 뒤 한 자리씩 돌아가며 말한다.
- 튜브를 포함해 게임에 참가하는 사람은 `m`명이고, 튜브의 순서는 `p`번째이다.
- 튜브가 말해야 하는 숫자 `t`개를 순서대로 이어 붙인 문자열을 반환한다.
- 10 이상의 숫자는 `A`부터 `F`까지의 대문자로 표현한다.

## 아이디어
- 모든 참가자가 말할 숫자를 순서대로 이어 붙인 문자열 `nums`를 만든다.
- 튜브가 숫자 `t`개를 말하려면 전체 문자열에 최소 `t * m`개의 문자가 필요하다.
- 각 정수를 `n`진법 문자열로 변환하여 `nums`에 계속 추가한다.
- 튜브가 처음 말하는 위치는 0-based 인덱스로 `p - 1`이다.
- 이후에는 참가자 수인 `m`칸씩 이동하며 문자를 선택하면 튜브가 말할 숫자만 얻을 수 있다.

## 시간복잡도
- 필요한 전체 자릿수는 `t * m`개이므로 진법 변환 결과를 생성하는 데 `O(t * m)`이 걸린다.
- 튜브가 말할 문자를 선택하는 데 `O(t)`가 걸리므로 전체 시간복잡도는 `O(t * m)`이다.

## 풀이 과정
1. `nums`를 `"0"`으로 초기화한다.
2. 정수 `1`부터 차례대로 `n`진법 문자열로 변환하여 `nums`에 추가한다.
3. `nums`의 길이가 튜브의 답을 구하기에 충분한 `t * m`보다 커질 때까지 반복한다.
4. 인덱스 `p - 1`부터 시작하여 `m`칸 간격으로 문자를 선택한다.
5. 선택한 문자 `t`개를 `answer`에 이어 붙여 반환한다.

## 코드 설명
```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string transform(int num, int n) {
    string digits = "0123456789ABCDEF";
    string s = "";
    while(num > 0) {
        s = digits[num%n] + s;
        num /= n;
    }
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string nums = "0";
    int i = 1;
    while(nums.size() <= t*m) {
        nums += transform(i,n);
        ++i;
    }
    
    for(int i = p-1 ; i < p + t*m -1 ; i += m)
        answer += nums[i];
    
    return answer;
}
```
- `digits`는 나머지 값 `0`부터 `15`까지를 해당 진법의 문자로 바꾸기 위한 문자열이다.
- `transform`은 숫자를 `n`으로 반복해서 나눈 나머지를 문자열 앞에 붙여 `n`진법 표현을 만든다.
- 숫자 `0`은 `nums`를 초기화할 때 미리 추가하므로 `transform`은 `1` 이상의 숫자만 처리한다.
- `while`문은 튜브가 말할 모든 위치를 확인할 수 있을 만큼 전체 숫자 문자열을 생성한다.
- `for`문은 튜브의 첫 번째 위치인 `p - 1`에서 시작해 `m`칸씩 이동하며 정확히 `t`개의 문자를 선택한다.
