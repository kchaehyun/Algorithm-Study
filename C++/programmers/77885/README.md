# Programmers 77885 - 2개 이하로 다른 비트

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/77885)
- 양의 정수가 담긴 배열 `numbers`가 주어진다.
- 각 수 `x`에 대해 `x`보다 크면서 이진수로 표현했을 때 서로 다른 비트가 1개 또는 2개인 수 중 가장 작은 수를 구한다.
- 각 숫자에 대해 구한 결과를 배열에 담아 반환한다.

## 아이디어
- 짝수는 이진수의 마지막 비트가 `0`이므로 `1`을 더하면 마지막 비트만 `1`로 바뀐다. 따라서 정답은 바로 `n + 1`이다.
- 홀수는 마지막 비트가 `1`이므로 단순히 `1`을 더하면 연속된 여러 비트가 바뀔 수 있다.
- 홀수의 이진수에서 오른쪽부터 가장 가까운 `0`을 찾아 `1`로 바꾸고, 그 바로 오른쪽의 `1`을 `0`으로 바꾸면 서로 다른 비트가 2개인 가장 작은 큰 수를 만들 수 있다.
- 모든 비트가 `1`인 경우에도 처리할 수 있도록 이진수 앞에 `"0"`을 붙인다.

## 풀이 과정
1. `numbers`의 각 숫자 `n`을 순회한다.
2. `n`이 짝수라면 마지막 비트만 바꾸면 되므로 `n + 1`을 정답에 추가한다.
3. `n`이 홀수라면 이진 문자열로 변환하고 앞에 `"0"`을 붙인다.
4. 이진 문자열을 오른쪽부터 탐색하며 가장 먼저 만나는 `0`을 찾는다.
5. 찾은 `0`을 `1`로 바꾸고, 바로 오른쪽 비트를 `0`으로 바꾼다.
6. 변경된 이진 문자열을 다시 십진수로 변환해 정답에 추가한다.
7. 모든 숫자의 처리가 끝나면 `answer`를 반환한다.

## 코드 설명
```cpp
string toBinary(long long n) {
    string result = "";
    while(n > 0) {
        result += n%2 + '0';
        n /= 2;        
    }
    reverse(result.begin(), result.end());
    return result;
}

long long toDecimal(string binary) {
    long long result = 0;
    for(char b : binary) {
        result *= 2;
        result += b - '0';
    }
    return result;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long n : numbers) {
        if(!(n%2)) {
            answer.push_back(n+1);
            continue;
        }
        string num = "0" + toBinary(n);
        for(int i = num.size()-1 ; i >= 0 ; --i) {
            if(num[i] == '0') {
                num[i] = '1';
                num[i+1] = '0';
                break;
            }
        }
        long long decimal = toDecimal(num);
        answer.push_back(decimal);        
    }
    return answer;
}
```
- `toBinary`는 숫자를 2로 계속 나누면서 나머지를 저장한 뒤 문자열을 뒤집어 이진수로 변환한다.
- `toDecimal`은 앞에서부터 현재 값에 2를 곱하고 비트 값을 더해 이진 문자열을 십진수로 변환한다.
- 짝수는 `n % 2 == 0`이므로 `n + 1`을 바로 정답에 넣는다.
- 홀수의 이진 문자열 앞에 `"0"`을 추가하면 `"111"`처럼 `0`이 없는 경우도 동일한 방식으로 처리할 수 있다.
- 오른쪽에서 가장 가까운 `0`을 `1`로 바꾸고 그 오른쪽의 `1`을 `0`으로 바꾸면 원래 수보다 크면서 증가 폭은 최소가 된다.

## 시간복잡도
- `numbers`의 길이를 `N`, 가장 큰 수의 비트 수를 `K`라고 하면 이진수 변환, 비트 탐색, 십진수 변환에 각각 O(K)가 필요하므로 전체 시간복잡도는 O(NK)이다.
- 가장 큰 수를 `M`이라고 표현하면 `K = log M`이므로 O(N log M)이다.
