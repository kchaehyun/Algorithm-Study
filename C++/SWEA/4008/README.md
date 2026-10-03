# SWEA 4008 - [모의 SW 역량테스트] 숫자 만들기

## 문제 설명

- [문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeRZV6kBUDFAVH)
- `N`개의 숫자와 덧셈, 뺄셈, 곱셈, 나눗셈 연산자의 개수가 주어진다. 연산자 개수의 합은 `N - 1`이다.
- 숫자의 순서를 유지하면서 숫자 사이에 주어진 연산자를 모두 배치한다.
- 연산자 우선순위를 적용하지 않고 왼쪽부터 차례대로 계산하며, 나눗셈은 소수점 이하를 버린 정수 결과를 사용한다.
- 가능한 모든 연산자 배치에서 계산 결과의 최댓값과 최솟값을 구하고, 두 값의 차이를 출력한다.
- 각 테스트 케이스의 정답을 `#테스트케이스번호 최댓값과최솟값의차이` 형식으로 출력한다.

## 아이디어

- DFS와 백트래킹으로 다음에 사용할 연산자를 하나씩 선택한다.
- `ops`에는 각 연산자의 남은 개수를 저장하고, 개수가 `0`보다 큰 연산자만 선택한다.
- 현재까지 계산한 값 `val`에 다음 숫자 `nums[idx + 1]`을 바로 연산하므로, 식 전체를 따로 저장하거나 다시 계산할 필요가 없다.
- 연산자를 선택하면 남은 개수를 하나 줄이고 재귀 호출한다. 탐색이 끝나면 개수를 복원하여 다른 선택에서도 사용할 수 있게 한다.
- 같은 종류의 연산자를 개별 카드로 구분하지 않고 개수로 관리하므로, 동일한 연산자 순서를 중복 탐색하지 않는다.
- `N - 1`개의 연산자를 모두 사용하면 현재 결과로 `maxVal`과 `minVal`을 갱신한다.
- 모든 배치를 탐색한 뒤 `maxVal - minVal`을 출력한다.

## 시간복잡도

- 숫자의 개수를 `N`이라 하면 연산자를 선택하는 단계는 `N - 1`번이고, 각 단계에서 최대 4종류의 연산자를 확인한다.
- 한 테스트 케이스의 시간복잡도 상한은 `O(4^(N - 1))`이다. 실제로는 남은 개수가 있는 연산자만 선택하므로 탐색량이 줄어든다.
- 네 종류의 연산자 개수를 각각 `a`, `b`, `c`, `d`라 하면, 완성되는 서로 다른 연산자 순서는 `(N - 1)! / (a! * b! * c! * d!)`개이다.
- 숫자 배열과 최대 `N`단계의 재귀 호출 스택을 사용하므로 공간복잡도는 `O(N)`이다. 연산자 개수 배열은 크기가 `4`로 고정되어 있다.

## 풀이 과정

1. 테스트 케이스마다 숫자의 개수 `N`, 연산자별 개수 `ops`, 숫자 배열 `nums`를 입력받는다.
2. 탐색 전에 `maxVal`을 `-1e9`, `minVal`을 `1e9`로 초기화한다.
3. `dfs(nums[0], 0, ops, nums)`를 호출하여 첫 번째 숫자를 초기 계산값으로 설정한다.
4. `idx == N - 1`이면 모든 숫자를 계산한 상태이므로 `maxVal`과 `minVal`을 갱신하고 반환한다.
5. 덧셈, 뺄셈, 곱셈, 나눗셈 순서로 남은 연산자 개수를 확인한다.
6. 사용할 수 있는 연산자의 개수를 하나 줄이고, `calc(val, nums[idx + 1], i)`로 다음 계산값을 구한다.
7. 계산값과 `idx + 1`을 전달하여 다음 연산자를 선택한다.
8. 재귀 호출이 끝나면 사용한 연산자의 개수를 하나 늘려 원래 상태로 복원한다.
9. 모든 탐색이 끝나면 테스트 케이스 번호와 `maxVal - minVal`을 출력한다.

## 코드 설명

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
//#include <cstdio>

using namespace std;

int N;
int maxVal;
int minVal;

int calc(int num1, int num2, int op) {
    switch (op) {
    case 0: return num1 + num2;
    case 1: return num1 - num2;
    case 2: return num1 * num2;
    case 3: return num1 / num2;
    }
    return 0;
}

void dfs(int val, int idx, vector<int>& ops, vector<int>& nums) {
    if (idx == N - 1) {
        maxVal = max(val, maxVal);
        minVal = min(val, minVal);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (ops[i] > 0) {
            --ops[i];
            dfs(calc(val, nums[idx + 1], i), idx+1, ops, nums);
            ++ops[i];
        }
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int answer;
        cin >> N;
        vector<int> ops(4);
        vector<int> nums(N);
        for (int i = 0; i < 4; ++i) cin >> ops[i];
        for (int i = 0; i < N; ++i) cin >> nums[i];

        maxVal = -1e9;
        minVal = 1e9;

        dfs(nums[0], 0, ops, nums);

        cout << "#" << test_case << " " << maxVal - minVal << endl;
    }
    return 0;
}
```

- `ops[0]`부터 `ops[3]`까지는 각각 덧셈, 뺄셈, 곱셈, 나눗셈 연산자의 남은 개수를 저장한다.
- `calc`는 연산자 번호 `op`를 받아 `switch`문으로 계산한다. `0`, `1`, `2`, `3`은 각각 `+`, `-`, `*`, `/`에 대응하므로 별도의 연산자 문자 배열이 필요 없다.
- `calc`의 마지막 `return 0`은 네 가지 연산자 번호에 해당하지 않을 때의 반환값이다. 현재 DFS는 `0`부터 `3`까지만 전달하므로 정상 탐색에서는 실행되지 않는다.
- C++의 정수 나눗셈은 소수 부분을 버려 `0` 방향으로 처리하므로, 예를 들어 `-7 / 3`은 `-2`가 된다.
- `dfs`의 `idx`는 마지막으로 계산에 포함한 숫자의 인덱스이자 지금까지 사용한 연산자의 개수이다. `val`은 `nums[0]`부터 `nums[idx]`까지 왼쪽부터 계산한 결과이다.
- `idx == N - 1`일 때 먼저 반환하므로, 마지막 숫자 뒤의 `nums[idx + 1]`에 접근하지 않는다.
- `ops`를 참조로 전달하므로 재귀 호출 사이에서 같은 배열을 공유한다. 따라서 `--ops[i]`로 선택한 뒤 `++ops[i]`로 복원하는 과정이 필요하다.
- `val`과 `idx`는 값으로 전달되므로, 하위 호출에서 계산한 결과가 상위 호출의 값에 영향을 주지 않는다.
- 각 단계에서 바로 계산하므로 `2 + 3 * 4`도 문제 규칙에 따라 `(2 + 3) * 4 = 20`으로 처리된다.
- `maxVal`과 `minVal`은 전역 변수이지만 매 테스트 케이스의 DFS 호출 전에 각각 `-1e9`, `1e9`로 초기화하므로 이전 결과가 남지 않는다.
