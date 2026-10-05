# SWEA 4012 - [모의 SW 역량테스트] 요리사

## 문제 설명

- [문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeUtVakTMDFAVH)
- `N`개의 식재료를 각각 `N / 2`개씩 나누어 음식 A와 음식 B를 만든다.
- 식재료 `i`와 `j`를 함께 사용하면 `s[i][j]`와 `s[j][i]`의 시너지가 발생한다.
- 음식의 맛은 해당 음식에 들어가는 모든 식재료 쌍의 시너지 합이다.
- 두 음식의 맛 차이의 절댓값이 최소가 되도록 식재료를 나누고, 그 최솟값을 구한다.
- 각 테스트 케이스의 정답을 `#테스트케이스번호 최소맛차이` 형식으로 출력한다.

## 아이디어

- DFS와 백트래킹으로 `N`개의 식재료 중 음식 A에 넣을 `N / 2`개를 선택한다.
- `selected[i]`가 `true`이면 음식 A에, `false`이면 음식 B에 속하는 식재료로 구분한다. 음식 A의 구성이 정해지면 음식 B는 남은 식재료로 자동 결정된다.
- 다음 재귀 호출에서는 선택한 인덱스보다 큰 인덱스부터 탐색하여, 같은 식재료를 다시 선택하거나 선택 순서만 다른 조합을 중복 생성하지 않는다.
- `N / 2`개를 모두 선택하면 `i < j`인 식재료 쌍을 확인한다. 두 식재료가 같은 음식에 속할 때만 `s[i][j] + s[j][i]`를 해당 음식의 맛에 더한다.
- 두 음식의 맛을 계산한 뒤 `abs(A - B)`로 정답의 최솟값을 갱신한다.
- 재귀 호출이 끝나면 선택 표시를 해제하여 다음 조합을 탐색한다.
- 현재 코드는 음식 A와 B의 구성이 서로 뒤바뀐 경우도 각각 탐색한다. 두 경우의 맛 차이는 같으므로 최솟값에는 영향을 주지 않는다.

## 시간복잡도

- 식재료의 개수를 `N`이라 하면, 음식 A에 들어갈 `N / 2`개를 선택하는 조합은 `C(N, N / 2)`개이다.
- 각 조합에서 이중 반복문으로 모든 식재료 쌍을 확인하므로 맛 계산에 `O(N^2)`의 시간이 걸린다.
- 따라서 한 테스트 케이스의 시간복잡도는 `O(C(N, N / 2) * N^2)`이다.
- 시너지 행렬 `s`에 `O(N^2)`, 선택 배열 `selected`와 재귀 호출 스택에 각각 `O(N)`의 공간이 필요하므로 전체 공간복잡도는 `O(N^2)`이다.

## 풀이 과정

1. 테스트 케이스마다 `answer`를 `20000`으로 초기화하고, 식재료의 개수 `N`을 입력받는다.
2. `N × N` 시너지 행렬 `s`를 입력받고, 선택 배열 `selected`를 모두 `false`로 초기화한다.
3. `dfs(0, 0, s, selected)`를 호출하여 아직 아무 식재료도 선택하지 않은 상태에서 탐색을 시작한다.
4. 선택한 개수 `cnt`가 `N / 2`이면 두 음식의 맛 `A`, `B`를 각각 `0`으로 초기화한다.
5. 모든 `i < j` 쌍에 대해 둘 다 선택되었으면 음식 A에, 둘 다 선택되지 않았으면 음식 B에 양방향 시너지 합을 더한다. 서로 다른 음식에 속하면 더하지 않는다.
6. `answer`를 `min(answer, abs(A - B))`로 갱신하고 현재 호출을 종료한다.
7. 아직 선택이 끝나지 않았다면 `start`부터 `N - 1`까지 순회하면서 `selected[i]`를 `true`로 설정한다.
8. `dfs(i + 1, cnt + 1, s, selected)`로 다음 식재료를 선택하고, 호출이 끝나면 `selected[i]`를 `false`로 복원한다.
9. 모든 조합을 탐색한 뒤 테스트 케이스 번호와 `answer`를 출력한다.

## 코드 설명

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>

using namespace std;

int N;
int answer;

void dfs(int start, int cnt, const vector<vector<int>>& s, vector<bool>& selected) {
    if (cnt == N / 2) {
        int A = 0, B = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                if (selected[i] && selected[j]) {
                    A += s[i][j] + s[j][i];
                }
                else if (!selected[i] && !selected[j]) {
                    B += s[i][j] + s[j][i];
                }
            }
        }
        answer = min(answer, abs(A - B));
        return;
    }
    for (int i = start; i < N; ++i) {
        selected[i] = true;
        dfs(i + 1, cnt + 1, s, selected);
        selected[i] = false;
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    //freopen("input_4012.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        answer = 20000;
        cin >> N;
        vector<vector<int>> s(N, vector<int>(N));
        vector<bool> selected(N, false);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> s[i][j];
            }
        }

        dfs(0, 0, s, selected);
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}
```

- `dfs`의 `start`는 다음에 선택할 수 있는 식재료 인덱스의 시작점이고, `cnt`는 지금까지 음식 A에 넣기로 선택한 식재료의 개수이다.
- `dfs(i + 1, cnt + 1, ...)`로 호출하므로 선택한 인덱스는 항상 증가한다. 예를 들어 `{0, 2}`를 선택한 뒤 `{2, 0}`을 다시 생성하지 않는다.
- `cnt == N / 2`일 때 선택되지 않은 식재료도 정확히 `N / 2`개이므로, 음식 B를 따로 선택하는 DFS가 필요 없다.
- `j`를 `i + 1`부터 시작하여 자기 자신과의 조합과 동일한 식재료 쌍의 중복 계산을 피한다. 이때 `s[i][j]`와 `s[j][i]`는 서로 다를 수 있으므로 두 값을 모두 더해야 한다.
- `selected[i] && selected[j]`는 두 식재료가 모두 음식 A에 속하는 경우이고, `!selected[i] && !selected[j]`는 모두 음식 B에 속하는 경우이다.
- `s`는 읽기 전용 참조로 전달하여 행렬 복사를 피하고, `selected`는 참조로 전달하여 재귀 호출 사이에서 선택 상태를 공유한다.
- 공유하는 `selected`를 재귀 호출 뒤에 `false`로 복원해야 이전 조합의 선택이 다음 조합에 남지 않는다.
- `A`와 `B`는 조합이 완성될 때마다 새로 계산하는 지역 변수이고, `answer`는 모든 조합에서 찾은 맛 차이의 최솟값을 저장하는 전역 변수이다.
- 테스트 케이스마다 `answer`를 다시 초기화하고 새로운 `s`, `selected`를 생성하므로 이전 테스트 케이스의 상태가 남지 않는다.
