# SWEA 2382 - [모의 SW 역량테스트] 미생물 격리

## 문제 설명

- [문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV597vbqAH0DFAVl)
- `N × N` 크기의 구역에 미생물 군집 `K`개가 있으며, 각 군집의 위치, 미생물 수, 이동 방향이 주어진다.
- 이동 방향은 `1`이 상, `2`가 하, `3`이 좌, `4`가 우이며, 각 군집은 한 시간마다 해당 방향으로 한 칸 이동한다.
- 가장자리에는 약품이 칠해져 있다. 군집이 가장자리에 도착하면 미생물 수가 절반으로 줄고, 이동 방향이 반대로 바뀐다. 미생물 수가 홀수이면 소수점 이하는 버린다.
- 미생물 수가 `0`이 된 군집은 사라진다.
- 이동 후 같은 칸에 여러 군집이 모이면 하나로 합쳐진다. 미생물 수는 합산하고, 이동 방향은 합쳐지기 전 미생물 수가 가장 많았던 군집의 방향을 따른다.
- `M`시간이 지난 뒤 남아 있는 미생물 수의 합을 구한다.
- 각 테스트 케이스의 정답은 `#테스트케이스번호 미생물수의합` 형식으로 출력한다.

## 아이디어

- **구현 / 시뮬레이션** 유형으로, 군집의 이동, 약품 처리, 병합을 시간 순서대로 구현한다.
- `Microbe` 구조체에 군집의 행 `r`, 열 `c`, 미생물 수 `cnt`, 이동 방향 `dir`을 저장한다.
- 매 시간마다 `pos`와 `maxCnt`를 새로 만든다. `pos[r][c]`는 이번 시간에 해당 칸으로 이동한 군집들을 대표하는 인덱스이고, `maxCnt[r][c]`는 그 칸에 도착한 개별 군집의 미생물 수 중 최댓값이다.
- 살아 있는 군집을 한 칸 이동시키고, 가장자리에 도착하면 미생물 수를 절반으로 줄인 뒤 방향을 반대로 바꾼다.
- 도착한 칸에 먼저 처리한 군집이 없다면 현재 군집을 대표로 등록한다. 이미 있다면 대표 군집에 미생물 수를 더하고, 현재 군집의 `cnt`를 `0`으로 만든다.
- 병합 방향은 `maxCnt`와 현재 군집의 미생물 수를 비교하여 결정한다. 대표 군집의 `cnt`는 여러 군집의 합이므로 방향을 정하는 비교 기준으로 사용할 수 없다.
- `M`번의 처리가 끝나면 모든 군집의 `cnt`를 합산한다. 사라지거나 흡수된 군집은 `0`이므로 그대로 더해도 된다.

## 시간복잡도

- 구역의 한 변의 길이를 `N`, 격리 시간을 `M`, 처음 군집 수를 `K`라 한다.
- 한 시간마다 `N × N` 크기의 `pos`, `maxCnt`를 초기화하는 데 `O(N^2)`, 군집 `K`개를 순회하는 데 `O(K)`가 걸린다.
- 따라서 한 테스트 케이스의 시간복잡도는 `O(M * (N^2 + K))`이다. 마지막 미생물 수 합산에는 `O(K)`가 걸린다.
- 군집 배열에 `O(K)`, 두 격자 배열에 `O(N^2)` 공간이 필요하므로 공간복잡도는 `O(N^2 + K)`이다. 격자 배열은 매 시간 새로 생성되지만 이전 시간의 배열은 해제되므로 공간에 `M`이 곱해지지 않는다.

## 풀이 과정

1. 테스트 케이스마다 `N`, `M`, `K`와 각 군집의 위치, 미생물 수, 이동 방향을 입력받는다.
2. `dr`, `dc`에 상하좌우 이동량을 저장하고, `opposite`에 각 방향의 반대 방향을 저장한다.
3. 매 시간마다 `pos`를 `-1`, `maxCnt`를 `0`으로 초기화한다.
4. 군집을 인덱스 순서대로 확인하면서 `cnt == 0`인 군집은 건너뛴다.
5. `dir - 1`을 방향 배열의 인덱스로 사용해 행과 열을 한 칸 이동시킨다.
6. 가장자리에 도착했다면 `cnt /= 2`로 미생물 수를 줄이고, `opposite`를 이용해 방향을 바꾼다. 미생물 수가 `0`이 되면 다음 군집으로 넘어간다.
7. 도착한 칸의 `pos`가 `-1`이면 현재 군집 인덱스를 등록하고, `maxCnt`에 현재 미생물 수를 기록한다.
8. 이미 대표 군집 `j`가 있다면 현재 군집의 미생물 수와 `maxCnt`를 비교한다. 현재 군집이 더 크면 `maxCnt`와 대표 군집의 방향을 갱신한다.
9. 대표 군집의 `cnt`에 현재 군집의 미생물 수를 더하고, 현재 군집의 `cnt`를 `0`으로 만든다.
10. 위 과정을 `M`시간 동안 반복한 뒤 모든 군집의 미생물 수를 합산하여 테스트 케이스 번호와 함께 출력한다.

## 코드 설명

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>

using namespace std;

struct Microbe {
    int r, c;
    int cnt;
    int dir;
};

int main(int argc, char** argv)
{
    int test_case;
    int T;
    //freopen("input_2382.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, M, K;
        int answer = 0;

        cin >> N >> M >> K;
        vector<Microbe> microbe(K);
        int dr[4] = { -1,1,0,0 };
        int dc[4] = { 0,0,-1,1 };
        vector<int> opposite = { 2,1,4,3 };

        for (int i = 0; i < K; ++i) {
            cin >> microbe[i].r >> microbe[i].c >> microbe[i].cnt >> microbe[i].dir;
        }

        for (int time = 0; time < M; ++time) {
            vector<vector<int>> pos(N, vector<int>(N, -1));
            vector<vector<int>> maxCnt(N, vector<int>(N, 0));
            for (int i = 0; i < K; ++i) {
                if (!microbe[i].cnt) continue;
                int maxIdx;
                microbe[i].r += dr[microbe[i].dir - 1];
                microbe[i].c += dc[microbe[i].dir - 1];
                if (microbe[i].r == 0 || microbe[i].r == N - 1 || microbe[i].c == 0 || microbe[i].c == N - 1) {
                    microbe[i].cnt /= 2;
                    microbe[i].dir = opposite[microbe[i].dir - 1];
                    if (!microbe[i].cnt) continue;
                }
                if (pos[microbe[i].r][microbe[i].c] != -1) {
                    int j = pos[microbe[i].r][microbe[i].c];
                    if (maxCnt[microbe[i].r][microbe[i].c] < microbe[i].cnt) {
                        maxCnt[microbe[i].r][microbe[i].c] = microbe[i].cnt;
                        microbe[j].dir = microbe[i].dir;
                    }
                    microbe[j].cnt += microbe[i].cnt;
                    microbe[i].cnt = 0;
                }
                else if (pos[microbe[i].r][microbe[i].c] == -1) {
                    pos[microbe[i].r][microbe[i].c] = i;
                    maxCnt[microbe[i].r][microbe[i].c] = microbe[i].cnt;
                }
            }
        }
        for (int i = 0; i < K; ++i) answer += microbe[i].cnt;

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}
```

- `dr`, `dc`의 인덱스 `0`, `1`, `2`, `3`은 각각 상, 하, 좌, 우에 대응한다. 입력 방향은 `1`부터 시작하므로 배열에 접근할 때 `dir - 1`을 사용한다.
- `opposite = { 2, 1, 4, 3 }`은 상과 하, 좌와 우를 서로 바꾼다. 저장된 값은 입력과 같은 `1`부터 `4`까지의 방향 번호이다.
- 가장자리 조건은 행이나 열이 `0` 또는 `N - 1`인지 확인한다. `cnt`가 양의 정수이므로 `cnt /= 2`는 홀수일 때 소수점 이하를 버리는 규칙도 처리한다.
- `pos`는 이번 시간에 이동을 마친 군집만 기록한다. 따라서 아직 이동하지 않은 군집의 위치와 충돌했다고 판단하지 않으며, 서로 자리를 맞바꾸는 두 군집도 합쳐지지 않는다.
- `pos[r][c] == -1`은 이번 시간에 해당 칸에 등록된 살아 있는 군집이 없다는 의미이다. 군집 인덱스 `0`도 유효하므로 빈 칸을 `-1`로 구분한다.
- 대표 군집은 해당 칸에 처음 등록된 군집이다. 나중에 더 큰 군집이 도착해도 대표 인덱스는 유지하고, 대표 군집의 방향만 갱신한다.
- 예를 들어 미생물 수가 `5`, `4`, `8`인 군집이 같은 칸에 차례로 도착하면, 앞의 두 군집을 합친 수는 `9`이지만 `maxCnt`는 `5`이다. 마지막 군집의 `8`과 `5`를 비교하므로 최종 미생물 수는 `17`, 방향은 원래 `8`마리였던 군집의 방향이 된다.
- 대표 군집 `j`는 현재 군집 `i`보다 먼저 처리되어 이미 이동을 마친 상태이다. 따라서 병합으로 대표 군집의 수와 방향이 바뀌어도 같은 시간에 다시 이동하지 않으며, 새 방향은 다음 시간부터 적용된다.
- 흡수된 군집을 벡터에서 삭제하는 대신 `cnt = 0`으로 표시한다. 이 방식은 `pos`에 저장한 인덱스를 유지하며, 다음 시간에는 `if (!microbe[i].cnt) continue;`로 해당 군집을 건너뛴다.
- `maxCnt`는 미생물 수의 합이 아니라 이번 시간에 해당 칸으로 들어온 개별 군집의 최대 크기이다. 다음 시간에는 병합된 군집 자체가 하나의 군집이 되므로 `pos`와 함께 새로 초기화한다.
