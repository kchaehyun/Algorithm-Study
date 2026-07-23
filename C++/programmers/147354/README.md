# Programmers 147354 - 테이블 해시 함수

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/147354)
- 정수로 이루어진 2차원 배열 `data`와 열 번호 `col`, 행 범위 `row_begin`, `row_end`가 주어진다.
- `data`를 `col`번째 열의 값을 기준으로 오름차순 정렬한다.
- 값이 같다면 첫 번째 열의 값을 기준으로 내림차순 정렬한다.
- 정렬된 테이블의 `i`번째 행에 대해 각 원소를 `i`로 나눈 나머지의 합 `S_i`를 구한다.
- `row_begin`부터 `row_end`까지의 모든 `S_i`를 비트 단위 XOR한 값을 반환한다.

## 아이디어
- 문제에서 주어진 두 정렬 조건을 비교 함수 `cmp`에 그대로 구현한다.
- 입력의 열 번호는 1부터 시작하지만 벡터의 인덱스는 0부터 시작하므로 `col - 1`을 정렬 기준 인덱스로 사용한다.
- 정렬된 배열에서 `row_begin - 1`부터 `row_end - 1`까지 순회한다.
- 코드의 행 인덱스가 `i`일 때 문제에서 정의한 행 번호는 `i + 1`이므로, 각 원소를 `i + 1`로 나눈 나머지를 더한다.
- 각 행에서 구한 합을 `answer`와 XOR하여 최종 해시 값을 만든다.

## 시간복잡도
- 행의 수를 `N`, 열의 수를 `M`이라고 하면 정렬에 O(N log N)이 걸린다.
- 선택된 행들의 나머지 합을 계산하는 데 최대 O(N × M)이 걸린다.
- 전체 시간복잡도는 O(N log N + N × M)이다.

## 풀이 과정
1. 정렬에 사용할 열의 인덱스를 `col - 1`로 설정한다.
2. `col`번째 열을 기준으로 오름차순 정렬한다.
3. `col`번째 열의 값이 같으면 첫 번째 열을 기준으로 내림차순 정렬한다.
4. 정렬된 테이블의 `row_begin`번째 행부터 `row_end`번째 행까지 순회한다.
5. 각 행의 모든 원소를 현재 행 번호로 나눈 나머지를 더해 `S_i`를 구한다.
6. `answer`와 `S_i`를 XOR한다.
7. 모든 대상 행의 계산이 끝나면 `answer`를 반환한다.

## 코드 설명
```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sortCol;

bool cmp(vector<int>& a, vector<int>& b) {
    if(a[sortCol] == b[sortCol]) return a[0] > b[0];
    return a[sortCol] < b[sortCol];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    sortCol = col-1;
    sort(data.begin(), data.end(), cmp);
    for(int i = row_begin-1 ; i < row_end ; ++i) {
        int sum = 0;
        for(int j = 0 ; j < data[0].size() ; ++j)
            sum += data[i][j]%(i+1);
        answer ^= sum;
    }
    return answer;
}
```
- `sortCol`에는 0부터 시작하는 실제 정렬 기준 열 인덱스를 저장한다.
- `cmp`는 정렬 기준 열의 값이 다르면 오름차순으로, 같으면 첫 번째 열의 값을 기준으로 내림차순 정렬한다.
- 반복문의 `i`는 0부터 시작하는 인덱스이므로 실제 행 번호는 `i + 1`이다.
- `data[i][j] % (i + 1)`을 모두 더해 해당 행의 `S_i`를 계산한다.
- `answer ^= sum`으로 각 행의 값을 누적 XOR하여 테이블의 해시 값을 구한다.
