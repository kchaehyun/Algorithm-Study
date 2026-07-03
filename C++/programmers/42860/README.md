# Programmers 42860 - 조이스틱

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42860)
- 처음 문자열은 모든 문자가 `A`로 이루어져 있다.
- 조이스틱을 위아래로 움직여 원하는 알파벳으로 바꾸고, 좌우로 움직여 다음 위치로 이동할 수 있다.
- 문자열 `name`을 만들기 위해 필요한 조이스틱 조작 횟수의 최솟값을 반환한다.

## 아이디어
- 각 문자를 `A`에서 목표 문자로 바꾸는 상하 이동 횟수는 독립적으로 계산할 수 있다.
- 알파벳은 순환하므로 `A`에서 위로 가는 횟수와 아래로 가는 횟수 중 더 작은 값을 더한다.
- 좌우 이동은 연속된 `A` 구간을 건너뛰는 경우를 고려해야 한다.
- 기본 이동 횟수는 왼쪽에서 오른쪽으로 끝까지 이동하는 `name.size() - 1`이다.
- 각 위치 `i`마다 뒤에 이어지는 `A` 구간의 끝 `next`를 찾고, 되돌아가는 두 가지 경로를 비교해 최소 좌우 이동 횟수를 갱신한다.

## 시간복잡도
- 문자열 길이를 `N`이라고 하면 각 위치에서 연속된 `A` 구간을 확인하므로 최악의 경우 O(N^2)
- Programmers 제한에서는 충분히 통과할 수 있다.

## 풀이 과정
1. 정답 변수 `answer`를 0으로 초기화한다.
2. 기본 좌우 이동 횟수 `move`를 `name.size() - 1`로 초기화한다.
3. 문자열의 각 인덱스 `i`를 순회한다.
4. 현재 문자로 바꾸기 위한 상하 이동 횟수 `min(name[i] - 'A', 'Z' - name[i] + 1)`을 `answer`에 더한다.
5. `i + 1`부터 시작해서 연속된 `A` 구간이 끝나는 위치 `next`를 찾는다.
6. 오른쪽으로 갔다가 다시 왼쪽으로 돌아오는 경로 `i * 2 + (name_size - next)`를 계산한다.
7. 왼쪽으로 먼저 갔다가 오른쪽으로 돌아오는 경로 `(name_size - next) * 2 + i`를 계산한다.
8. 두 경로와 기존 `move` 중 최솟값을 저장한다.
9. 모든 문자를 처리한 뒤 `answer + move`를 반환한다.

## 코드 설명
```cpp
int up(char target, char original) {
    return target-original;
}

int down(char target, char original) {
    return original+26-target;
}

int solution(string name) {
    int answer = 0;
    int next = 0;
    int name_size = name.size();
    int move = name_size - 1;
    for(int i = 0 ; i < name_size ; ++i) {
        answer += min(up(name[i],'A'), down(name[i],'A'));
        
        next = i+1;
        while(next < name_size && name[next] == 'A') next++;
        
        move = min(move, i*2 + (name_size-next));
        move = min(move, (name_size-next)*2 + i);
        
    }
    return answer+move;
}
```
- `up(name[i], 'A')`는 `A`에서 목표 문자까지 위로 이동하는 횟수이다.
- `down(name[i], 'A')`는 `A`에서 아래 방향으로 돌아 목표 문자까지 이동하는 횟수이다.
- `next`는 현재 위치 뒤에 있는 연속된 `A` 구간을 건너뛴 다음 위치를 의미한다.
- `i * 2 + (name_size - next)`는 오른쪽으로 `i`까지 갔다가 다시 왼쪽으로 돌아가 뒤쪽을 처리하는 경우이다.
- `(name_size - next) * 2 + i`는 왼쪽 방향으로 뒤쪽을 먼저 처리하고 다시 오른쪽으로 돌아오는 경우이다.
- `answer`에는 상하 이동 횟수, `move`에는 최소 좌우 이동 횟수를 저장하므로 최종 결과는 `answer + move`이다.
