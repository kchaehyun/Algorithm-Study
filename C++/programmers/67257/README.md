# Programmers 67257 - 수식 최대화

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/67257)
- 숫자와 `+`, `-`, `*` 연산자로 이루어진 수식 문자열 `expression`이 주어진다.
- 세 연산자의 우선순위를 자유롭게 정할 수 있다.
- 같은 연산자는 같은 우선순위를 가지며, 우선순위에 따라 수식을 계산했을 때 나올 수 있는 결과의 절댓값 중 최댓값을 구해야 한다.

## 아이디어
- 가능한 연산자 우선순위는 `+`, `-`, `*`의 순열 6가지뿐이다.
- 먼저 수식 문자열을 숫자 배열 `nums`와 연산자 배열 `ops`로 분리한다.
- 각 우선순위 조합마다 원본 배열을 복사한 뒤, 우선순위가 높은 연산자부터 차례대로 계산한다.
- 특정 연산자를 만나면 양옆 숫자를 계산 결과로 합치고, 사용한 오른쪽 숫자와 연산자를 배열에서 제거한다.
- 모든 연산을 마치면 숫자 하나만 남으므로 그 절댓값으로 정답을 갱신한다.

## 시간복잡도
- 수식 길이를 `N`이라고 할 때, 문자열 파싱은 O(N)이다.
- 우선순위 조합은 6가지로 고정되어 있다.
- 각 조합에서 연산자를 찾고 `vector`에서 원소를 지우는 과정 때문에 최악의 경우 O(N²)이 걸린다.
- 따라서 전체 시간복잡도는 O(N²)이다.

## 풀이 과정
1. 가능한 연산자 우선순위 6가지를 `combinations`에 저장한다.
2. `expression`을 순회하며 숫자는 `tmp`에 이어 붙인다.
3. 연산자를 만나면 지금까지 만든 숫자를 `nums`에 넣고, 연산자는 `ops`에 넣는다.
4. 마지막 숫자까지 `nums`에 추가한다.
5. 각 우선순위 조합마다 `nums`와 `ops`를 복사한다.
6. 현재 우선순위의 연산자를 `tmpOps`에서 왼쪽부터 찾는다.
7. 해당 연산자를 찾으면 `tmpNums[i]`와 `tmpNums[i + 1]`을 계산해 `tmpNums[i]`에 저장한다.
8. 계산에 사용된 `tmpNums[i + 1]`과 `tmpOps[i]`를 제거한다.
9. 한 조합의 모든 연산이 끝나면 남은 값의 절댓값으로 정답을 갱신한다.

## 코드 설명
```cpp
long long solution(string expression) {
    long long answer = 0;
    vector<string> combinations = {"+-*", "+*-", "-+*", "-*+", "*+-", "*-+"};
    vector<long long> nums;
    vector<char> ops;
    string tmp;
    for(char c : expression) {
        if(c == '+' || c == '-' || c == '*') {
            nums.push_back(stoll(tmp));
            ops.push_back(c);
            tmp = "";
            continue;
        }
        tmp += c;
    }
    nums.push_back(stoll(tmp));
    for(string combination : combinations) {
        vector<long long> tmpNums = nums;
        vector<char> tmpOps = ops;
        for(char c : combination) {
            int i = 0;
            while(i < tmpOps.size()) {
                if(c == tmpOps[i]) {
                    if(c == '+') {
                        tmpNums[i] += tmpNums[i+1];
                    }
                    else if(c == '-') {
                        tmpNums[i] -= tmpNums[i+1];
                    }
                    else if(c == '*') {
                        tmpNums[i] *= tmpNums[i+1];
                    }
                    tmpNums.erase(tmpNums.begin() + i+1);
                    tmpOps.erase(tmpOps.begin() + i);
                    continue;
                }
                ++i;
            }
        }
        answer = max(answer, abs(tmpNums[0]));
    }
    return answer;
}
```
- `combinations`에는 가능한 연산자 우선순위 6가지를 모두 저장한다.
- `nums`에는 피연산자, `ops`에는 연산자를 순서대로 분리해 저장한다.
- 각 우선순위 조합마다 원본 배열을 보존하기 위해 `tmpNums`, `tmpOps`로 복사한다.
- `continue`를 사용해 연산 후 같은 인덱스를 다시 확인한다. 원소 삭제로 다음 연산자가 현재 인덱스로 당겨질 수 있기 때문이다.
- `tmpNums[0]`에는 해당 우선순위로 계산한 최종 결과가 남는다.
- 정답은 결과값의 절댓값 중 최댓값이므로 `max(answer, abs(tmpNums[0]))`로 갱신한다.
