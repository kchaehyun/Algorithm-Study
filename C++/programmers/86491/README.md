# Programmers 86491 - 최소직사각형

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/86491)
- 여러 명함의 가로와 세로 길이가 `sizes` 배열로 주어진다.
- 모든 명함을 넣을 수 있는 가장 작은 지갑의 크기를 구해야 한다.
- 명함은 회전할 수 있으므로 가로와 세로를 바꾸어 넣을 수 있다.

## 아이디어
- 각 명함마다 긴 쪽을 가로, 짧은 쪽을 세로가 되도록 맞춘다.
- 이렇게 하면 모든 명함의 방향 기준이 같아진다.
- 이후 전체 명함 중 가장 긴 가로 길이와 가장 긴 세로 길이를 찾는다.
- 두 값을 곱하면 모든 명함을 담을 수 있는 최소 지갑의 넓이가 된다.

## 시간복잡도
- O(N)

## 풀이 과정
1. 최대 가로 길이를 저장할 `max_w`와 최대 세로 길이를 저장할 `max_h`를 0으로 초기화한다.
2. `sizes` 배열을 처음부터 끝까지 순회한다.
3. 현재 명함의 가로가 세로보다 작으면 `swap`으로 두 값을 바꾼다.
4. 현재 명함의 가로와 `max_w`를 비교해 더 큰 값을 저장한다.
5. 현재 명함의 세로와 `max_h`를 비교해 더 큰 값을 저장한다.
6. 최종적으로 `max_w * max_h`를 반환한다.

## 코드 설명
```cpp
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int tmp, max_w = 0, max_h = 0;
    for(int i = 0 ; i < sizes.size() ; ++i) {
        if (sizes[i][0] < sizes[i][1]) {
            swap(sizes[i][0], sizes[i][1]);
        }
        if (max_w < sizes[i][0]) max_w = sizes[i][0];
        if (max_h < sizes[i][1]) max_h = sizes[i][1];
    }
    return max_w * max_h;
}
```
- `sizes[i][0] < sizes[i][1]`이면 현재 명함은 세로가 더 긴 상태이다.
- `swap(sizes[i][0], sizes[i][1])`로 긴 쪽을 가로 방향에 배치한다.
- `max_w`는 정리된 명함들 중 가장 긴 가로 길이를 저장한다.
- `max_h`는 정리된 명함들 중 가장 긴 세로 길이를 저장한다.
- `max_w * max_h`가 모든 명함을 넣을 수 있는 최소 지갑의 넓이이다.
