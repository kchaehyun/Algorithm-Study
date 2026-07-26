# Programmers 131701 - 연속 부분 수열 합의 개수

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/131701)
- 원형 수열을 나타내는 정수 배열 `elements`가 주어진다.
- 원형 수열에서 연속하는 부분 수열을 만들 수 있으며, 부분 수열의 길이는 1부터 `elements.size()`까지 가능하다.
- 만들 수 있는 모든 연속 부분 수열의 합 중 서로 다른 값의 개수를 반환한다.

## 아이디어
- 부분 수열의 길이를 1부터 전체 수열의 길이까지 하나씩 늘려 가며 확인한다.
- 각 길이에 대해 모든 원소를 부분 수열의 시작점으로 사용한다.
- 원형 수열의 끝을 넘어간 인덱스는 `(시작점 + 이동 거리) % 수열의 길이`로 처리한다.
- 각 부분 수열의 합을 `set`에 저장하면 중복된 합은 자동으로 제거된다.
- 모든 경우를 확인한 뒤 `set`의 크기를 반환한다.

## 풀이 과정
1. 수열의 길이를 `size`에 저장한다.
2. 서로 다른 부분 수열의 합을 저장할 `set<int> sums`를 선언한다.
3. 부분 수열의 길이 `i`를 1부터 `size`까지 순회한다.
4. 각 길이에 대해 시작 인덱스 `j`를 0부터 `size - 1`까지 순회한다.
5. `k`를 0부터 `i - 1`까지 순회하며 `elements[(j + k) % size]`를 더한다.
6. 계산한 합을 `sums`에 삽입한다.
7. 모든 부분 수열을 확인한 뒤 `sums.size()`를 반환한다.

## 코드 설명
```cpp
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int size = elements.size();
    set<int> sums;
    for(int i = 1 ; i <= size ; ++i) {
        for(int j = 0 ; j < size ; ++j) {
            int sum = 0;
            for(int k = 0 ; k < i ; ++k)
                sum += elements[(j+k)%size];
            sums.insert(sum);
        }
    }
    return sums.size();
}
```
- `i`는 연속 부분 수열의 길이를 의미한다.
- `j`는 연속 부분 수열의 시작 인덱스를 의미한다.
- `(j + k) % size`를 사용하여 수열의 마지막 원소 다음을 첫 번째 원소로 연결한다.
- `set`은 같은 합을 여러 번 삽입해도 하나만 저장하므로 서로 다른 합의 개수를 구할 수 있다.

## 시간복잡도
- 수열의 길이를 `N`이라고 하면 길이별 부분 수열의 합 계산에는 `N × N × 평균 길이`만큼의 연산이 필요하므로 O(N³)이 걸린다.
- 계산한 합을 `set`에 삽입할 때마다 O(log M)이 걸리며, `M`은 서로 다른 합의 개수이고 최대 O(N²)이다.
- 따라서 전체 시간복잡도는 O(N³ + N² log N)이며, O(N³)으로 볼 수 있다.
- `set`에는 최대 O(N²)개의 서로 다른 합이 저장되므로 공간복잡도는 O(N²)이다.
