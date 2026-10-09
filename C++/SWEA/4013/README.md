# SWEA 4013 - [모의 SW 역량테스트] 특이한 자석

## 문제 설명

- [문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeV9sKkcoDFAVH)
- 8개의 날을 가진 자석 4개가 일렬로 놓여 있으며, 각 날의 자성은 N극이면 `0`, S극이면 `1`로 주어진다.
- 각 자석의 상태는 맨 위의 날부터 시계 방향 순서로 주어진다.
- `K`개의 회전 명령에 따라 지정한 자석을 한 칸씩 회전한다. 방향 `1`은 시계 방향, `-1`은 반시계 방향이다.
- 회전 전에 서로 맞닿은 날의 자성이 다르면 이웃 자석도 반대 방향으로 회전한다. 자성이 같으면 그 방향으로 회전이 전달되지 않는다.
- 모든 명령을 수행한 뒤 맨 위의 날이 S극인 자석에 대해 1번부터 각각 `1`, `2`, `4`, `8`점을 더한다.
- 각 테스트 케이스의 정답은 `#테스트케이스번호 점수` 형식으로 출력한다.

## 아이디어

- 자석의 상태를 `4 × 8` 크기의 배열 `magnetics`에 저장하고, 회전 명령을 순서대로 시뮬레이션한다.
- 각 자석의 인덱스 `0`은 맨 위, `2`는 오른쪽 접점, `6`은 왼쪽 접점이다. 따라서 이웃한 자석은 왼쪽 자석의 `[2]`와 오른쪽 자석의 `[6]`을 비교한다.
- 매 명령마다 `rotate`를 모두 `0`으로 초기화하고, 지정한 자석의 회전 방향을 먼저 기록한다.
- 지정한 자석에서 왼쪽과 오른쪽을 각각 확인한다. 접점의 자성이 다르면 이웃 자석의 방향을 현재 자석과 반대로 정하고, 같으면 해당 방향의 탐색을 중단한다.
- 모든 자석의 회전 방향을 결정한 다음 실제로 회전한다. 도중에 자석을 먼저 돌리면 접점이 바뀌어 회전 전 상태를 기준으로 판단할 수 없기 때문이다.
- 시계 방향은 배열을 오른쪽으로 한 칸, 반시계 방향은 왼쪽으로 한 칸 순환 이동하여 구현한다.
- 모든 명령이 끝나면 각 자석의 `[0]`을 확인하고, 값이 `1`인 자석의 점수를 합산한다.

## 시간복잡도

- 회전 명령의 개수를 `K`라 하면, 한 명령에서 최대 3쌍의 접점을 비교하고 최대 4개의 자석을 회전한다.
- 자석은 4개, 각 자석의 날은 8개로 고정되어 있으므로 명령 하나를 처리하는 시간은 `O(1)`이다.
- 따라서 한 테스트 케이스의 시간복잡도는 `O(K)`이다.
- 현재 코드는 모든 회전 명령을 `num`, `dir`에 저장하므로 공간복잡도는 `O(K)`이다. 자석 상태와 회전 방향 배열에 필요한 공간은 `O(1)`이다.

## 풀이 과정

1. 테스트 케이스마다 회전 횟수 `K`를 입력받고, 점수 `score`를 `0`으로 초기화한다.
2. 자석 4개의 상태를 `magnetics`에 입력받는다.
3. 회전시킬 자석 번호와 방향을 각각 `num`, `dir`에 저장한다.
4. 각 명령마다 `rotate`를 모두 `0`으로 초기화하고, `idx = num[i] - 1`로 자석 번호를 배열 인덱스로 바꾼다.
5. `rotate[idx]`에 명령의 회전 방향 `dir[i]`를 기록한다.
6. 왼쪽으로 이동하면서 `magnetics[left][2]`와 `magnetics[left + 1][6]`을 비교한다. 다르면 반대 방향을 기록하고, 같으면 중단한다.
7. 오른쪽으로 이동하면서 `magnetics[right][6]`과 `magnetics[right - 1][2]`를 비교한다. 다르면 반대 방향을 기록하고, 같으면 중단한다.
8. 자석 4개에 대해 `move(magnetics[i], rotate[i])`를 호출하여 결정된 방향으로 회전한다.
9. 모든 명령이 끝나면 `magnetics[i][0] == 1`인 자석의 점수 `2^i`를 `score`에 더한다.
10. 테스트 케이스 번호와 `score`를 출력한다.

## 코드 설명

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <cmath>

using namespace std;

void move(vector<int>& magnetic, int dir) {
    if (dir == 1) {
        int tmp = magnetic[7];
        for (int i = 7; i > 0; --i)
            magnetic[i] = magnetic[i-1];
        magnetic[0] = tmp;
    }
    else if (dir == -1) {
        int tmp = magnetic[0];
        for (int i = 0; i < 7 ; ++i)
            magnetic[i] = magnetic[i + 1];
        magnetic[7] = tmp;
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    freopen("input_4013.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int K;
        cin >> K;
        int score = 0;

        vector<vector<int>> magnetics(4, vector<int>(8));
        vector<int> num(K);
        vector<int> dir(K);

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 8; ++j) cin >> magnetics[i][j];
        }
        for (int i = 0; i < K; ++i)
            cin >> num[i] >> dir[i];

        for (int i = 0; i < K; ++i) {
            vector<int> rotate(4, 0);
            int idx = num[i] - 1;
            rotate[idx] = dir[i];
            for (int left = idx - 1; left >= 0; --left) {
                int cur = left + 1;
                if (magnetics[left][2] != magnetics[cur][6])
                    rotate[left] = rotate[cur] * -1;
                else break;
            }
            for (int right = idx + 1; right < 4; ++right) {
                int cur = right - 1;
                if (magnetics[right][6] != magnetics[cur][2])
                    rotate[right] = rotate[cur] * -1;
                else break;
            }
            for (int i = 0; i < 4; ++i) {
                move(magnetics[i], rotate[i]);
            }
        }

        for (int i = 0; i < 4; ++i) {
            if (magnetics[i][0] == 1) score += pow(2, i);
        }
        cout << "#" << test_case << " " << score << endl;
    }
    return 0;
}
```

- `magnetics[i][j]`는 `i + 1`번 자석의 `j`번째 위치에 있는 날의 자성을 나타낸다. 회전할 때 배열 값을 직접 이동하므로 접점 인덱스는 항상 `2`, `6`으로 고정된다.
- `rotate`의 값 `0`은 회전하지 않음, `1`은 시계 방향, `-1`은 반시계 방향을 의미한다. 매 명령마다 새로 생성하므로 이전 명령의 회전 방향이 남지 않는다.
- 왼쪽 탐색의 `cur = left + 1`, 오른쪽 탐색의 `cur = right - 1`은 회전 방향이 이미 결정된 이웃 자석을 가리킨다.
- 접점의 자성이 다를 때 `rotate[cur] * -1`을 저장하여 회전 방향을 반대로 전달한다. 같은 자성을 만나면 `break`하므로 그 너머의 자석은 `rotate`가 `0`인 상태로 남는다.
- 왼쪽과 오른쪽 탐색은 독립적이다. 한쪽에서 회전 전달이 끊겨도 다른 쪽의 탐색은 계속 수행한다.
- `move`는 자석 벡터를 참조로 받아 원본을 수정한다. `dir == 0`이면 어느 조건에도 들어가지 않아 상태가 유지된다.
- 시계 방향 회전은 마지막 값을 `tmp`에 보관하고 뒤에서부터 값을 옮긴다. 반시계 방향 회전은 첫 값을 보관하고 앞에서부터 옮긴다. 이 순서로 이동해야 아직 복사하지 않은 값을 덮어쓰지 않는다.
- 모든 `rotate`가 결정된 뒤에는 자석을 순서대로 수정해도 된다. 이 단계에서는 접점을 다시 비교하지 않으므로 동시에 회전한 것과 같은 결과를 얻는다.
- `pow(2, i)`는 자석 인덱스 `0`, `1`, `2`, `3`에 대해 각각 `1`, `2`, `4`, `8`을 계산한다. 맨 위가 N극이면 점수를 더하지 않는다.
- `freopen("input_4013.txt", "r", stdin)`은 로컬 파일을 표준 입력으로 연결한다. 온라인 제출 시에는 해당 줄을 주석 처리하거나 제거하여 채점 입력을 받도록 한다.
