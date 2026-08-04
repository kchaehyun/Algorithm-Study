# Programmers 12949 - 행렬의 곱셈

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/12949)
- 두 개의 2차원 행렬 `arr1`과 `arr2`가 주어진다.
- `arr1`과 `arr2`를 곱한 결과 행렬을 반환한다.

## 아이디어
- 행렬 곱셈의 정의를 그대로 구현한다.
- `arr1`이 `R x N`, `arr2`가 `N x C` 크기라면 결과 행렬은 `R x C` 크기이다.
- 결과 행렬의 `(r, c)` 원소는 `arr1`의 `r`번째 행과 `arr2`의 `c`번째 열에서 같은 위치의 원소끼리 곱한 값의 합이다.
- 따라서 `answer[r][c]`에 `arr1[r][n] * arr2[n][c]`를 모든 `n`에 대해 누적한다.

## 시간복잡도
- `arr1`의 행 수를 `R`, 공통 차원을 `N`, `arr2`의 열 수를 `C`라고 할 때 시간복잡도는 O(R * N * C)이다.
- 결과 행렬을 저장하는 공간복잡도는 O(R * C)이다.

## 풀이 과정
1. 행의 수가 `arr1.size()`, 열의 수가 `arr2[0].size()`인 결과 행렬을 `0`으로 초기화한다.
2. `arr1`의 각 행 `r`을 순회한다.
3. `arr2`의 각 열 `c`를 순회한다.
4. 공통 차원의 인덱스 `n`을 순회하며 `arr1[r][n] * arr2[n][c]`를 `answer[r][c]`에 더한다.
5. 모든 원소의 계산을 마친 결과 행렬을 반환한다.

## 코드 설명
```cpp
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    for(int r = 0 ; r < arr1.size() ; ++r) {
        for(int c = 0 ; c < arr2[0].size() ; ++c) {
            for(int n = 0 ; n < arr1[0].size() ; ++n) {
                answer[r][c] += arr1[r][n] * arr2[n][c];
            }
        }
    }
    return answer;
}
```
- `answer`는 `arr1`의 행 개수와 `arr2`의 열 개수를 이용해 결과 행렬의 크기로 생성한다.
- 바깥쪽 두 반복문은 결과 행렬에서 계산할 위치 `(r, c)`를 선택한다.
- 가장 안쪽 반복문의 `n`은 `arr1`의 열이자 `arr2`의 행을 가리키는 공통 인덱스이다.
- 각 곱을 `answer[r][c]`에 누적하면 `arr1`의 `r`번째 행과 `arr2`의 `c`번째 열의 내적이 완성된다.
