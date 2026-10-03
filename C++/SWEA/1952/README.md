# SWEA 1952 - [모의 SW 역량테스트] 수영장

## 문제 설명

- [문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq)
- 1년 동안 각 달의 수영장 이용 일수와 이용권 4종류의 가격이 주어진다.
- 이용권은 1일 이용권, 1개월 이용권, 연속된 3개월을 이용할 수 있는 3개월 이용권, 1년 이용권으로 구성된다.
- 월별 이용 계획을 모두 만족하도록 이용권을 선택했을 때의 최소 비용을 구한다.
- 각 테스트 케이스의 정답을 `#테스트케이스번호 최소비용` 형식으로 출력한다.

## 아이디어

- 현재 달부터 남은 이용 계획을 처리하는 DFS로 이용권 선택을 탐색한다.
- 1일 이용권으로 해당 달을 이용하는 비용은 `months[month] * costs[0]`이고, 1개월 이용권의 비용은 `costs[1]`이다.
- 두 선택 모두 다음 달로 이동하므로, 더 저렴한 비용만 남겨 하나의 분기로 처리한다.
- 다른 분기에서는 3개월 이용권을 구매하고 세 달 뒤로 이동한다.
- 1년 이용권 하나로 모든 이용 계획을 만족할 수 있으므로, `answer`를 1년 이용권 가격으로 초기화한다.
- 누적 비용이 이미 `answer`보다 크면 이후 이용권을 추가해도 더 저렴해질 수 없으므로 탐색을 중단한다.
- 이용 일수가 `0`인 달은 비용 없이 다음 달로 넘어간다. 3개월 이용권의 구매 시점을 다음 이용 달로 미뤄도 필요한 이용 기간을 같은 비용으로 충족할 수 있으므로, 이 달에는 별도의 구매 분기가 필요 없다.

## 시간복잡도

- 한 테스트 케이스에서 처리할 달의 수를 `M`이라 하면, 각 DFS 호출은 최대 두 갈래로 나뉘고 재귀 깊이는 최대 `M`이다.
- 가지치기를 고려하지 않은 시간복잡도의 상한은 `O(2^M)`이다. 실제 분기는 한 달 또는 세 달씩 진행하므로 모든 단계에서 두 갈래로 나뉘는 경우보다 탐색량이 작다.
- 월별 이용 일수를 저장하는 배열과 재귀 호출 스택에 필요한 공간복잡도는 `O(M)`이다.
- 이 문제에서는 `M = 12`로 고정되어 있으므로 테스트 케이스 하나당 시간과 공간은 상수 범위이며, 테스트 케이스가 `T`개라면 전체 시간복잡도는 `O(T)`로 볼 수 있다.

## 풀이 과정

1. 테스트 케이스마다 이용권 가격 4개를 `costs`에, 12개월의 이용 일수를 `months`에 입력받는다.
2. `answer`를 1년 이용권 가격인 `costs[3]`으로 초기화한다.
3. `dfs(0, 0, months, costs)`를 호출하여 1월부터 누적 비용 `0`으로 탐색한다.
4. 누적 비용 `cost`가 `answer`보다 크면 현재 탐색을 종료한다.
5. `month > 11`이면 12개월을 모두 처리한 것이므로 `answer`를 현재 비용과 비교해 갱신한다.
6. 현재 달의 이용 일수가 `0`이면 비용을 추가하지 않고 다음 달을 탐색한 뒤 반환한다.
7. 1일 이용권과 1개월 이용권 중 더 저렴한 비용을 누적 비용에 더해 다음 달을 탐색한다.
8. 3개월 이용권 가격을 누적 비용에 더해 세 달 뒤를 탐색한다.
9. 모든 탐색이 끝나면 테스트 케이스 번호와 `answer`를 출력한다.

## 코드 설명

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
// #include <cstdio>

using namespace std;

int answer = 0;

void dfs(int month, int cost, vector<int>& months, vector<int>& costs) {
    if (cost > answer) return;
    if (month > 11) {
        answer = min(answer, cost);
        return;
    }
    if (!months[month]) {
        dfs(month + 1, cost + months[month] * costs[0], months, costs);
        return;
    }
    int oneMonth = min(cost + months[month] * costs[0], cost + costs[1]);
    dfs(month + 1, oneMonth, months, costs);
    dfs(month + 3, cost + costs[2], months, costs);
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    // freopen("input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        vector<int> costs(4);
        vector<int> months(15);
        for (int i = 0; i < 4; ++i) cin >> costs[i];
        for (int i = 0; i < 12; ++i) cin >> months[i];
        answer = costs[3];

        dfs(0, 0, months, costs);

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}
```

- `costs[0]`, `costs[1]`, `costs[2]`, `costs[3]`은 각각 1일, 1개월, 3개월, 1년 이용권 가격이다.
- `months[0]`부터 `months[11]`까지 1월부터 12월의 이용 일수를 저장한다. 벡터는 크기 `15`로 생성하지만 실제 이용 계획은 앞의 12칸만 사용한다.
- `dfs`의 `month`는 다음으로 처리할 달의 인덱스이고, `cost`는 그 전까지 선택한 이용권의 누적 비용이다.
- `oneMonth`는 현재 달만의 비용이 아니라, 현재 달까지 처리한 누적 비용이다. 두 후보에 같은 `cost`가 더해지므로 해당 달의 더 저렴한 이용 방법을 선택할 수 있다.
- `months`와 `costs`를 참조로 전달하므로 재귀 호출마다 벡터를 복사하지 않는다.
- 이용 일수가 `0`이면 `months[month] * costs[0]`도 `0`이므로 누적 비용이 그대로 유지된다.
- 3개월 이용권을 선택하면 해당 기간의 이용 일수를 따로 계산하지 않고 `month + 3`으로 이동한다. 연말에 이 값이 `12` 이상이 되어도 종료 조건을 먼저 확인하므로 배열에 접근하지 않는다.
- `answer`는 전역 변수이지만 테스트 케이스마다 `costs[3]`으로 다시 설정하므로 이전 정답이 다음 탐색에 영향을 주지 않는다.
