# SWEA 5644 - [모의 SW 역량테스트] 무선 충전

## 문제 설명

- [문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRDL1aeugDFAUo)
- `10 × 10` 크기의 지도에서 사용자 A는 `(1, 1)`, 사용자 B는 `(10, 10)`에서 출발하며, `m`초 동안의 이동 정보가 주어진다.
- 이동 명령은 `0`이 이동하지 않음, `1`이 상, `2`가 우, `3`이 하, `4`가 좌를 의미한다.
- 무선 충전기 BC가 `a`개 있으며, 각 BC의 위치, 충전 범위 `c`, 성능 `p`가 주어진다.
- 사용자와 BC 사이의 맨해튼 거리 `|x1 - x2| + |y1 - y2|`가 충전 범위 이하이면 해당 BC에 접속할 수 있다.
- 사용자는 한 시점에 하나의 BC를 선택할 수 있다. 두 사용자가 서로 다른 BC를 선택하면 각 BC의 성능만큼 충전하고, 같은 BC를 선택하면 그 BC의 성능을 균등하게 나누어 충전한다.
- 이동 전인 `0`초부터 마지막 이동을 마친 `m`초까지 충전할 수 있다. 전체 시간 동안 두 사용자가 충전한 양의 합을 최대로 만든다.
- 각 테스트 케이스의 정답은 `#테스트케이스번호 최대충전량` 형식으로 출력한다.

## 아이디어

- **구현 / 시뮬레이션 / 완전탐색** 유형으로, 주어진 경로대로 두 사용자를 이동시키고 매 시점의 BC 선택 조합을 모두 확인한다.
- `BC` 구조체에 충전기의 열 `col`, 행 `row`, 충전 범위 `c`, 성능 `p`를 저장한다.
- 각 시점에 모든 BC와 두 사용자 사이의 맨해튼 거리를 계산하여 접속 가능 여부를 `isCharge`에 기록한다.
- A가 선택할 BC 인덱스 `i`와 B가 선택할 BC 인덱스 `j`를 이중 반복문으로 탐색한다. `-1`은 충전기를 선택하지 않는 경우를 의미한다.
- 두 사용자가 같은 BC를 선택하면 두 사람의 충전량 합은 해당 BC의 `p`이다. 서로 다른 BC를 선택하면 선택한 BC들의 `p`를 더한다.
- 각 사용자가 접속 가능한 조합만 계산하고, 그중 최댓값 `maxCharge`를 전체 정답 `answer`에 더한다.
- 이동 경로는 이미 정해져 있고 현재의 BC 선택이 다음 시점의 위치나 충전기 성능에 영향을 주지 않는다. 따라서 각 시점의 최대 충전량을 더하면 전체 최대 충전량을 얻을 수 있다.
- `time = 0`에서는 이동 없이 시작 위치에서 충전하고, 이후에는 두 사용자를 이동시킨 뒤 충전량을 계산한다.

## 시간복잡도

- 이동 시간을 `m`, BC의 개수를 `a`라 한다.
- 한 시점에서 접속 가능 여부를 확인하는 데 `O(a)`가 걸리고, 충전하지 않는 선택까지 포함한 최대 `(a + 1)^2`개의 조합을 확인한다.
- 충전량을 계산하는 시점은 `0`초부터 `m`초까지 총 `m + 1`개이므로, 한 테스트 케이스의 시간복잡도는 `O((m + 1) * (a + 1)^2)`이다. `m`, `a`가 양수인 문제 조건에서는 `O(m * a^2)`로 나타낼 수 있다.
- 두 사용자의 이동 배열에 `O(m)`, BC 정보와 접속 가능 여부 배열에 `O(a)` 공간이 필요하므로 공간복잡도는 `O(m + a)`이다.

## 풀이 과정

1. 테스트 케이스마다 이동 시간 `m`, BC 개수 `a`, 두 사용자의 이동 명령 배열 `A`, `B`를 입력받는다.
2. 각 BC의 열, 행, 충전 범위, 성능을 `bc`에 저장한다.
3. A의 위치를 `(1, 1)`, B의 위치를 `(10, 10)`으로 설정하고, 누적 충전량 `answer`를 `0`으로 초기화한다.
4. `time`을 `0`부터 `m`까지 순회하며 `isCharge`를 모두 `false`로 초기화한다.
5. `time > 0`이면 `A[time - 1]`, `B[time - 1]`에 따라 두 사용자의 위치를 갱신한다.
6. 각 BC에 대해 `isPossible`로 A와 B의 접속 가능 여부를 확인하여 `isCharge[i][0]`, `isCharge[i][1]`에 기록한다.
7. 두 사용자의 BC 선택을 각각 `-1`부터 `a - 1`까지 탐색하며, 접속할 수 없는 BC를 선택한 경우는 건너뛴다.
8. 같은 BC를 선택하면 해당 BC의 성능을 한 번만 더하고, 서로 다른 BC를 선택하면 각자의 충전량을 더한다. `-1`을 선택한 사용자의 충전량은 `0`이다.
9. 모든 조합 중 최댓값을 `maxCharge`에 저장한 뒤 `answer`에 더한다.
10. 마지막 시점까지 처리한 후 테스트 케이스 번호와 `answer`를 출력한다.

## 코드 설명

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>

using namespace std;

struct BC {
    int col, row;
    int c;
    int p;
};

bool isPossible(int x, int y, int tx, int ty, int c) {
    if (abs(tx - x) + abs(ty - y) <= c) return true;
    return false;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    //freopen("input_5644.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int m, a;
        cin >> m >> a;
        vector<int> A(m);
        vector<int> B(m);
        for (int i = 0; i < m; ++i) cin >> A[i];
        for (int i = 0; i < m; ++i) cin >> B[i];
        vector<BC> bc(a);
        for (int i = 0; i < a; ++i) cin >> bc[i].col >> bc[i].row >> bc[i].c >> bc[i].p;
        int answer = 0;;
        int aC = 1, aR = 1;
        int bC = 10, bR = 10;

        int dr[5] = { 0,-1,0,1,0 };
        int dc[5] = { 0,0,1,0,-1 };

        for (int time = 0; time <= m; ++time) {
            vector<vector<bool>> isCharge(a, vector<bool>(2, false));
            if (time > 0) {
                aR += dr[A[time-1]];
                aC += dc[A[time-1]];
                bR += dr[B[time-1]];
                bC += dc[B[time-1]];
            }
            for (int i = 0; i < a; ++i) {
                if (isPossible(bc[i].col, bc[i].row, aC, aR, bc[i].c)) isCharge[i][0] = true;
                if (isPossible(bc[i].col, bc[i].row, bC, bR, bc[i].c)) isCharge[i][1] = true;
            }

            int maxCharge = 0;
            for (int i = -1; i < a; ++i) {
                if (i != -1 && !isCharge[i][0]) continue;
                for (int j = -1; j < a; ++j) {
                    if (j != -1 && !isCharge[j][1]) continue;
                    int charge = 0;
                    if (i != -1 && i == j) {
                        charge += bc[i].p;
                    }
                    else {
                        if (i != -1) charge += bc[i].p;
                        if (j != -1) charge += bc[j].p;
                    }
                    maxCharge = max(charge, maxCharge);
                }
            }
            answer += maxCharge;
        }
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}
```

- 입력 좌표는 열, 행 순서이므로 `BC`도 `col`, `row` 순서로 저장한다. `aC`, `bC`는 열 좌표이고, `aR`, `bR`은 행 좌표이다.
- `dr`, `dc`의 인덱스는 이동 명령과 같다. `0`의 이동량은 모두 `0`이고, 위로 이동하면 행이 감소하며 오른쪽으로 이동하면 열이 증가한다.
- `isPossible`은 가로 거리와 세로 거리의 합을 충전 범위와 비교한다. `<= c`를 사용하므로 범위의 경계에 있는 사용자도 충전할 수 있다.
- `time <= m` 조건으로 시작 시점과 마지막 이동 후 시점을 모두 포함한다. `time > 0`일 때만 이동 배열에 접근하므로 실제 사용 인덱스는 `0`부터 `m - 1`까지이다.
- `isCharge[i][0]`은 A가 `i`번 BC를 사용할 수 있는지, `isCharge[i][1]`은 B가 사용할 수 있는지를 나타낸다. 매 시점 새로 생성하므로 이전 위치의 접속 정보가 남지 않는다.
- `-1`을 선택지에 포함하면 한 명만 충전하거나 두 명 모두 충전할 수 없는 경우도 같은 반복문에서 처리할 수 있다.
- `i != -1 && !isCharge[i][0]`은 단락 평가를 이용한다. `i`가 `-1`이면 뒤쪽 조건을 평가하지 않으므로 음수 인덱스로 배열에 접근하지 않는다. B에 대한 조건도 같은 방식이다.
- `i != -1 && i == j`는 두 사용자가 실제로 같은 BC를 선택한 경우이다. 이때 각각 `p / 2`를 받으므로 두 사람의 합은 `p`이며, 코드에서는 `bc[i].p`를 한 번만 더한다.
- 예를 들어 A는 성능 `100`, `80`인 두 BC에 접속할 수 있고 B는 성능 `100`인 BC에만 접속할 수 있다고 하자. 둘 다 성능 `100`인 BC를 선택하면 합은 `100`이지만, A가 `80`, B가 `100`인 BC를 선택하면 합은 `180`이다. 따라서 두 사용자의 선택을 함께 비교해야 한다.
- `charge`는 특정 선택 조합의 충전량 합, `maxCharge`는 현재 시점의 최대 충전량, `answer`는 모든 시점의 최대 충전량을 누적한 값이다.
