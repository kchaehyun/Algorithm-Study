# Programmers 42748 - K번째수

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42748)
- 배열 `array`와 명령 배열 `commands`가 주어진다.
- 각 명령은 `[i, j, k]` 형태이며, `array`의 `i`번째부터 `j`번째까지 자른 뒤 정렬한다.
- 정렬한 배열에서 `k`번째 수를 구해 순서대로 반환한다.

## 아이디어
- 각 명령마다 필요한 구간만 새로운 벡터 `tmp`로 복사한다.
- 복사한 구간을 오름차순으로 정렬한다.
- 정렬된 `tmp`에서 `k - 1`번 인덱스 값을 꺼내 `answer`에 추가한다.
- 문제의 `i`, `j`, `k`는 1부터 시작하므로 C++ 인덱스에 맞게 1을 빼서 접근한다.

## 시간복잡도
- 명령의 개수를 `M`, 잘라낸 구간의 최대 길이를 `N`이라고 하면 O(M * N log N)

## 풀이 과정
1. 결과를 저장할 벡터 `answer`를 만든다.
2. `commands`를 처음부터 끝까지 순회한다.
3. 현재 명령의 `i`와 `j`를 이용해 `array`의 부분 구간을 `tmp`에 복사한다.
4. `tmp`를 오름차순으로 정렬한다.
5. `tmp[k - 1]` 값을 `answer`에 추가한다.
6. 모든 명령을 처리한 뒤 `answer`를 반환한다.

## 코드 설명
```cpp
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int c = 0 ; c < commands.size() ; ++c) {
        vector<int> tmp(array.begin() + commands[c][0] - 1, array.begin() + commands[c][1]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[c][2]-1]);
    }
    return answer;
}
```
- `array.begin() + commands[c][0] - 1`은 자르기 시작할 위치를 가리킨다.
- `array.begin() + commands[c][1]`은 C++ 범위 생성자의 끝 위치가 포함되지 않는 특성을 이용한 것이다.
- `sort(tmp.begin(), tmp.end())`로 잘라낸 배열을 오름차순 정렬한다.
- `tmp[commands[c][2] - 1]`로 정렬된 배열의 k번째 수를 선택한다.
