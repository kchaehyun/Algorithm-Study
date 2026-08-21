# Programmers 64062 - 징검다리 건너기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/64062)
- 디딤돌마다 밟을 수 있는 횟수를 나타내는 배열 `stones`와 한 번에 건너뛸 수 있는 최대 칸 수 `k`가 주어진다.
- 한 사람이 디딤돌을 밟을 때마다 해당 디딤돌의 숫자가 1씩 감소하며, 숫자가 0인 디딤돌은 밟을 수 없다.
- 건널 수 없는 디딤돌이 `k`개 연속하면 더 이상 징검다리를 건널 수 없다.
- 징검다리를 건널 수 있는 최대 인원수를 구한다.

## 아이디어
- 정답이 될 수 있는 인원수는 디딤돌의 최솟값부터 최댓값 사이에 있으므로 이분 탐색을 사용한다.
- 후보 인원수를 `mid`라고 할 때, 내구도가 `mid`보다 작은 디딤돌은 `mid`명이 건너는 과정에서 사용할 수 없게 된다.
- 사용할 수 없는 디딤돌이 `k`개 이상 연속하면 `mid`명은 건널 수 없으므로 탐색 범위를 왼쪽으로 줄인다.
- 반대로 연속한 개수가 `k`보다 작으면 `mid`명은 건널 수 있으므로 `answer`를 갱신하고 더 큰 인원수를 탐색한다.
- `is_available` 함수는 각 디딤돌의 내구도가 후보 인원수 이상인지 여부를 `vector<bool>`로 반환한다.

## 시간 복잡도
- 디딤돌의 개수를 `N`, 디딤돌 내구도의 최댓값을 `M`이라고 하면 한 후보값을 검사하는 데 O(N)이 필요하다.
- 후보 인원수를 이분 탐색하므로 전체 시간 복잡도는 O(N log M)이다.
- 사용 가능 여부를 저장하는 배열 때문에 공간 복잡도는 O(N)이다.

## 풀이 과정
1. 이분 탐색의 범위를 `stones`의 최솟값과 최댓값으로 설정한다.
2. 중간값 `mid`를 현재 확인할 인원수로 정한다.
3. 각 디딤돌에 대해 `stone - mid < 0`이면 사용할 수 없는 디딤돌로 표시한다.
4. 사용 불가능한 디딤돌의 최대 연속 길이 `maxlen`을 구한다.
5. `maxlen`이 `k` 이상이면 `mid`명은 건널 수 없으므로 `right`를 `mid - 1`로 줄인다.
6. 그렇지 않으면 `mid`명은 건널 수 있으므로 `answer`를 갱신하고 `left`를 `mid + 1`로 늘린다.
7. 탐색이 끝난 뒤 마지막으로 건널 수 있다고 확인한 `answer`를 반환한다.

## 코드 설명
```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<bool> is_available(vector<int>* arr, int n) {
    vector<bool> available;
    for(int a : *arr) {
        if(a-n < 0) available.push_back(false);
        else available.push_back(true);
    }
    return available;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = *min_element(stones.begin(), stones.end());
    int right = *max_element(stones.begin(), stones.end());
    
    while(left <= right) {
        int mid = (left + right)/2;
        vector<bool> av = is_available(&stones, mid);
        int maxlen = 0, curlen = 0;
        for(int i = 0 ; i < av.size() ; ++i) {
            if(!av[i]) ++curlen;
            else curlen = 0;
            maxlen = max(maxlen, curlen);
        }
        if(maxlen >= k)
            right = mid-1;
        
        else {
            left = mid+1;
            answer = mid;
        }
    }
    
    return answer;
}
```
- `left`와 `right`는 가능한 인원수의 탐색 범위이고, `mid`는 현재 건널 수 있는지 검사할 인원수이다.
- `is_available`은 내구도가 `mid` 이상인 디딤돌을 `true`, 미만인 디딤돌을 `false`로 표시한다.
- `curlen`은 현재 연속한 사용 불가능 디딤돌의 개수이고, `maxlen`은 그중 가장 긴 길이이다.
- `maxlen >= k`이면 건널 수 없는 구간이 생긴 것이므로 현재 인원수는 불가능하다.
- 이분 탐색이 종료되면 `answer`에는 건널 수 있다고 판정된 가장 큰 인원수가 저장된다.
