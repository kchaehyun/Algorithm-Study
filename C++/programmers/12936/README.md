# Programmers 12936 - 줄 서는 방법

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/12936)
- `1`부터 `n`까지의 자연수를 중복 없이 나열한 모든 방법을 사전순으로 정렬한다.
- 주어진 `k`번째 순서에 해당하는 숫자의 나열을 반환한다.

## 아이디어
- 첫 번째 자리의 숫자가 같은 순열은 각각 `(n - 1)!`개씩 하나의 그룹을 이룬다.
- `k`를 0부터 시작하는 인덱스로 바꾸면 `k / (n - 1)!`로 첫 번째 자리에 올 숫자를 결정할 수 있다.
- 숫자를 하나 고른 뒤에는 해당 숫자를 후보에서 제거한다.
- `k %= (n - 1)!`로 선택한 그룹 안에서의 순서를 구한 후, 남은 자리에도 같은 방법을 반복한다.

## 시간복잡도
- 중간 원소를 `vector::erase` 할 때마다 뒤의 원소를 이동해야 하므로 시간복잡도는 O(N²)이다.
- 사용 가능한 숫자와 팩토리얼을 저장하므로 공간복잡도는 O(N)이다.

## 풀이 과정
1. `0!`부터 `20!`까지의 팩토리얼 값을 미리 계산한다.
2. `1`부터 `n`까지의 숫자를 `nums`에 저장한다.
3. `k`를 0 기반 인덱스로 사용하기 위해 1을 뺀다.
4. 남은 자리가 `i`개일 때, 한 숫자로 시작하는 순열의 개수인 `(i - 1)!`을 구한다.
5. `k / (i - 1)!`번째 숫자를 정답에 추가하고 `nums`에서 제거한다.
6. `k`를 `k % (i - 1)!`로 갱신하고 남은 자리를 같은 방법으로 결정한다.

## 코드 설명
```cpp
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> nums;
    long long factorial[21];
    factorial[0] = 1;
    for(int i = 1 ; i <= 20 ; ++i) {
        factorial[i] = factorial[i-1] * i;
    }
    for(int i = 1 ; i <= n ; ++i) nums.push_back(i);
    k--;
    for(int i = n ; i > 0 ; --i) {
        if(i == 1) {
            answer.push_back(nums[0]);
            break;
        }
        long long digit = factorial[i-1];
        answer.push_back(nums[k/digit]);
        nums.erase(nums.begin() + k/digit);
        k = k%digit;
    }
    return answer;
}
```
- `factorial[i]`는 `i!`을 저장하며, 크기가 큰 팩토리얼을 다루기 위해 `long long`을 사용한다.
- `k--`는 1부터 시작하는 문제의 순서를 0 기반 인덱스로 변환한다.
- `factorial[i - 1]`은 현재 자리에서 각 후보 숫자가 차지하는 순열 그룹의 크기이다.
- `nums[k / digit]`는 현재 자리에 올 숫자이다.
- 선택한 숫자를 `nums`에서 제거해 각 숫자가 한 번씩만 사용되도록 한다.
- `k % digit`으로 현재 그룹 안에서 찾아야 할 새로운 순서를 구한다.
