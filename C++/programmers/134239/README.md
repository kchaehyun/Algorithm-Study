# Programmers 134239 - 우박수열 정적분

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/134239)
- 양의 정수 `k`에 우박수 변환을 반복하여 `1`이 될 때까지의 수열을 만든다.
  - `k`가 짝수이면 `k / 2`
  - `k`가 홀수이면 `3 * k + 1`
- 수열의 각 값을 y좌표, 수열의 인덱스를 x좌표로 하여 인접한 점들을 직선으로 연결한다.
- 각 `ranges`의 `[a, b]`에 대해 구간 `[a, n + b]`의 정적분 값을 구한다. 이때 `n`은 우박수 변환 횟수이다.
- 시작점이 끝점보다 크면 유효하지 않은 구간이므로 `-1.0`을 반환한다.

## 아이디어
- 먼저 `k`가 `1`이 될 때까지 우박수 변환을 수행하고, 각 값을 `seq`에 저장한다.
- 인접한 두 점 사이의 가로 길이는 항상 `1`이므로 해당 구간의 넓이는 사다리꼴 넓이 공식에 따라 `(seq[i] + seq[i + 1]) / 2.0`이다.
- 각 요청 구간의 시작 인덱스는 `range[0]`, 끝 인덱스는 `n + range[1]`이다.
- 시작 인덱스가 끝 인덱스보다 크면 `-1.0`을 저장한다.
- 유효한 구간이면 시작점부터 끝점 직전까지 각 사다리꼴의 넓이를 더한다.

## 풀이 과정
1. 초기값 `k`를 `seq`에 넣고, 짝수와 홀수 조건에 따라 다음 값을 계산한다.
2. `k`가 `1`이 될 때까지 변환을 반복한 뒤 마지막 값 `1`도 `seq`에 저장한다.
3. `seq.size() - 1`을 전체 변환 횟수 `n`으로 설정한다.
4. 각 `range`에 대해 적분 구간 `[range[0], n + range[1]]`을 계산한다.
5. 시작점이 끝점보다 크면 `-1.0`을 정답에 추가한다.
6. 그렇지 않으면 구간에 포함되는 사다리꼴의 넓이를 모두 더해 정답에 추가한다.

## 코드 설명
```cpp
#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> seq;
    while(k != 1) {
        seq.push_back(k);
        if(!(k%2)) k /= 2;
        else k = k*3 + 1;
    }
    seq.push_back(1);
    
    int n = seq.size() - 1;
    for(vector<int> range : ranges) {
        if(range[0] > n + range[1]) {
            answer.push_back(-1.0);
            continue;
        }
        double area = 0.0;
        for(int i = range[0] ; i < n+range[1] ; ++i)
            area += (seq[i] + seq[i+1]) / 2.0;
        answer.push_back(area);
    }
    return answer;
}
```
- `seq`에는 초기값부터 `1`까지의 우박수열이 순서대로 저장된다.
- `n`은 수열의 구간 개수이자 우박수 변환이 일어난 횟수이다.
- `range[1]`은 전체 구간의 끝 `n`을 기준으로 한 상대적인 값이므로 실제 끝점은 `n + range[1]`이다.
- `(seq[i] + seq[i + 1]) / 2.0`에서 `2.0`으로 나누어 실수 나눗셈을 수행한다.
- 적분 구간의 양 끝점이 같으면 반복문이 실행되지 않아 넓이 `0.0`이 저장된다.

## 시간 복잡도
- 우박수 변환 횟수를 `N`, 요청 구간의 개수를 `R`이라고 하자.
- 우박수열을 만드는 데 O(N)이 걸린다.
- 각 요청이 최악의 경우 전체 구간을 순회하므로 모든 정적분 계산에는 O(RN)이 걸린다.
- 따라서 전체 시간 복잡도는 O(RN)이다.
- 우박수열을 저장하는 공간 복잡도는 O(N)이며, 반환 배열을 제외한 추가 공간도 O(N)이다.
