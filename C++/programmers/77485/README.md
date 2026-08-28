# Programmers 77485 - 행렬 테두리 회전하기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/77485)
- `rows x columns` 크기의 행렬이 있고, 행렬에는 1부터 `rows * columns`까지의 숫자가 순서대로 채워져 있다.
- 각 쿼리 `[x1, y1, x2, y2]`는 `(x1, y1)`부터 `(x2, y2)`까지의 직사각형 테두리를 시계 방향으로 한 칸 회전시킨다.
- 각 회전에서 움직인 숫자 중 가장 작은 값을 배열에 담아 반환한다.
- 좌표는 1부터 시작한다.

## 아이디어
- 행렬을 먼저 문제 조건대로 초기화한다.
- 쿼리 좌표는 0-based 인덱스로 변환해 사용한다.
- 테두리의 왼쪽 위 값을 `prev`에 저장한 뒤, 위쪽, 오른쪽, 아래쪽, 왼쪽 순서로 값을 한 칸씩 밀어 넣는다.
- 값을 덮어쓰기 전에 기존 값을 `tmp`에 저장하고, 다음 칸으로 넘겨야 할 값으로 사용한다.
- 회전 중 만나는 값들을 `minVal`과 비교해 해당 쿼리의 최솟값을 구한다.

## 풀이 과정
1. `rows x columns` 크기의 `matrix`를 만들고 1부터 차례대로 값을 채운다.
2. 각 쿼리의 좌표 `x1, y1, x2, y2`를 0-based로 변환한다.
3. 회전 시작 값인 `matrix[x1][y1]`을 `prev`에 저장한다.
4. 위쪽 행을 왼쪽에서 오른쪽으로 이동하며 값을 한 칸씩 민다.
5. 오른쪽 열을 위에서 아래로 이동하며 값을 한 칸씩 민다.
6. 아래쪽 행을 오른쪽에서 왼쪽으로 이동하며 값을 한 칸씩 민다.
7. 왼쪽 열을 아래에서 위로 이동하며 값을 한 칸씩 민다.
8. 회전 중 확인한 최솟값을 `answer`에 추가한다.
9. 모든 쿼리를 처리한 뒤 `answer`를 반환한다.

## 코드 설명
```cpp
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix(rows, vector<int>(columns));
    for(int i = 0 ; i < rows ; ++i) {
        for(int j = 0 ; j < columns ; ++j)
            matrix[i][j] = columns*i + j + 1;
    }
    for(vector<int> q : queries) {
        int x1 = q[0]-1;
        int y1 = q[1]-1;
        int x2 = q[2]-1;
        int y2 = q[3]-1;
        int prev = matrix[x1][y1];
        int minVal = 101*101;
        for(int y = y1+1 ; y <= y2 ; ++y) {
            int tmp = matrix[x1][y];
            minVal = min(tmp, minVal);
            matrix[x1][y] = prev;
            prev = tmp;
        }
        for(int x = x1+1 ; x <= x2 ; ++x) {
            int tmp = matrix[x][y2];
            minVal = min(tmp, minVal);
            matrix[x][y2] = prev;
            prev = tmp;
        }
        for(int y = y2-1 ; y >= y1 ; --y) {
            int tmp = matrix[x2][y];
            minVal = min(tmp, minVal);
            matrix[x2][y] = prev;
            prev = tmp;
        }
        for(int x = x2-1 ; x >= x1 ; --x) {
            int tmp = matrix[x][y1];
            minVal = min(tmp, minVal);
            matrix[x][y1] = prev;
            prev = tmp;
        }
        answer.push_back(minVal);
    }
    return answer;
}
```
- `matrix[i][j] = columns * i + j + 1`로 행렬을 초기 상태로 채운다.
- `prev`는 현재 칸에 넣을 이전 위치의 값이다.
- `tmp`는 현재 칸의 기존 값이며, 다음 칸으로 넘길 값이 된다.
- 네 개의 반복문은 각각 위쪽, 오른쪽, 아래쪽, 왼쪽 테두리를 담당한다.
- `minVal`은 문제의 최대 행렬 값이 `100 * 100`이므로 그보다 큰 `101 * 101`로 초기화한다.

## 시간복잡도
- 한 쿼리에서 회전하는 테두리 길이는 최대 `2 * rows + 2 * columns`이다.
- 쿼리 개수를 `Q`라고 하면 전체 시간복잡도는 O(Q * (rows + columns))이다.
- 행렬 초기화에는 O(rows * columns)이 필요하다.
