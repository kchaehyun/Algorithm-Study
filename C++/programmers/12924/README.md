# Programmers 12924 - 숫자의 표현

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/12924)
- 자연수 `n`이 주어진다.
- `n`을 연속된 자연수들의 합으로 표현하는 방법의 수를 반환한다.
- 예를 들어 `15`는 `1 + 2 + 3 + 4 + 5`, `4 + 5 + 6`, `7 + 8`, `15`로 표현할 수 있으므로 정답은 `4`이다.

## 아이디어
- 연속된 자연수의 합은 시작점 `left`와 끝점 `right`로 이루어진 구간 합으로 볼 수 있다.
- 현재 구간 합 `sum`이 `n`보다 작으면 더 큰 수를 포함해야 하므로 `right`를 증가시킨다.
- `sum`이 `n`보다 크면 앞쪽의 작은 수를 제외해야 하므로 `left`를 증가시킨다.
- `sum`이 `n`과 같으면 하나의 표현 방법을 찾은 것이므로 정답을 증가시키고, 다음 경우를 찾기 위해 `left`를 이동한다.
- 모든 시작점이 `n`을 넘어가기 전까지 위 과정을 반복한다.

## 시간복잡도
- `left`와 `right`는 각각 최대 `n`까지 한 방향으로만 이동한다.
- 따라서 시간복잡도는 O(N)이다.
- 별도의 배열을 사용하지 않으므로 공간복잡도는 O(1)이다.

## 풀이 과정
1. `left`, `right`를 `1`로 두고 현재 구간 합 `sum`을 `1`로 초기화한다.
2. `left <= n`인 동안 반복한다.
3. `sum == n`이면 정답을 `1` 증가시키고 `left` 값을 구간에서 제외한다.
4. `sum < n`이면 `right`를 `1` 증가시키고 새 `right` 값을 `sum`에 더한다.
5. `sum > n`이면 현재 `left` 값을 `sum`에서 빼고 `left`를 `1` 증가시킨다.
6. 반복이 끝나면 찾은 표현 방법의 수를 반환한다.

## 코드 설명
```cpp
int solution(int n) {
    int answer = 0;
    int left = 1, right = 1;
    int sum = 1;
    while(left <= n) {
        if(sum == n) {
            ++answer;
            sum -= left;
            ++left;
        }
        else if(sum < n) {
            ++right;
            sum += right;
        }
        else if(sum > n) {
            sum -= left;
            ++left;
        }
    }

    return answer;
}
```
- `left`와 `right`는 현재 확인 중인 연속 자연수 구간의 양 끝이다.
- `sum`은 `left`부터 `right`까지의 합이다.
- `sum == n`인 경우 현재 구간이 하나의 정답이므로 `answer`를 증가시킨다.
- 이후 `left`를 이동해 같은 구간을 다시 세지 않고 다음 구간을 확인한다.
- `sum < n`이면 구간 오른쪽을 넓혀 합을 키우고, `sum > n`이면 구간 왼쪽을 줄여 합을 낮춘다.
