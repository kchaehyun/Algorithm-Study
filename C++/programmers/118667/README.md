# Programmers 118667 - 두 큐 합 같게 만들기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/118667)
- 길이가 같은 두 개의 큐 `queue1`, `queue2`가 주어진다.
- 한 번의 작업으로 한 큐의 맨 앞 원소를 꺼내 다른 큐의 맨 뒤에 넣을 수 있다.
- 두 큐에 들어 있는 원소의 합이 같아지도록 만드는 데 필요한 최소 작업 횟수를 반환한다.
- 두 큐의 합을 같게 만들 수 없다면 `-1`을 반환한다.

## 아이디어
- 두 큐의 전체 합이 홀수라면 정확히 절반으로 나눌 수 없으므로 바로 `-1`을 반환한다.
- 현재 두 큐의 합 `sum1`, `sum2`를 비교한다.
- `sum1`이 더 크면 `queue1`의 맨 앞 원소를 `queue2`로 옮긴다.
- `sum2`가 더 크면 `queue2`의 맨 앞 원소를 `queue1`로 옮긴다.
- 모든 원소가 양수이므로 합이 큰 큐에서 원소를 빼는 선택이 두 합의 차이를 줄이기 위한 유일한 방향이다.
- 원소를 옮길 때마다 두 큐의 합을 직접 갱신하면 매번 큐 전체의 합을 다시 구할 필요가 없다.
- 정해진 최대 횟수 안에 두 합이 같아지지 않으면 같은 상태가 반복될 수 있으므로 `-1`을 반환한다.

## 시간복잡도
- 두 큐에 들어 있는 원소의 총개수를 `N`이라고 하면, 합을 구하고 큐에 원소를 넣는 데 O(N)이 걸린다.
- 원소 이동도 최대 O(N)번 수행하므로 전체 시간복잡도는 O(N)이다.
- 두 큐를 별도로 저장하므로 공간복잡도는 O(N)이다.

## 풀이 과정
1. `queue1`, `queue2`의 합을 각각 `sum1`, `sum2`에 저장한다.
2. 두 합의 총합이 홀수라면 `-1`을 반환한다.
3. 입력 벡터의 원소를 실제 큐 `q1`, `q2`에 넣는다.
4. 두 큐의 합이 다르고 작업 횟수가 제한을 넘지 않는 동안 반복한다.
5. `sum1 < sum2`이면 `q2`의 맨 앞 원소를 꺼내 `q1`에 넣고 두 합을 갱신한다.
6. `sum1 > sum2`이면 `q1`의 맨 앞 원소를 꺼내 `q2`에 넣고 두 합을 갱신한다.
7. 두 합이 같아졌다면 작업 횟수를, 같아지지 않았다면 `-1`을 반환한다.

## 코드 설명
```cpp
int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    if((sum1+sum2) % 2 != 0) return -1;
    
    int answer = 0;
    int maxN = (queue1.size() + queue2.size())*2;
    queue<int> q1;
    queue<int> q2;
    for(int q : queue1) q1.push(q);
    for(int q : queue2) q2.push(q);
    
    while(sum1 != sum2 && answer < maxN) {
        if(sum1 < sum2) {
            int num = q2.front();
            q2.pop();
            q1.push(num);
            sum1 += num;
            sum2 -= num;
        }
        else if(sum1 > sum2) {
            int num = q1.front();
            q1.pop();
            q2.push(num);
            sum1 -= num;
            sum2 += num;
        }
        ++answer;
    }
    return sum1 == sum2 ? answer : -1;
}
```
- `sum1`, `sum2`는 원소의 합이 커질 수 있으므로 `long long`으로 선언한다.
- `maxN`은 원소 이동을 무한히 반복하지 않도록 탐색 횟수를 제한한다.
- 합이 더 큰 큐의 맨 앞 원소를 꺼내 합이 더 작은 큐의 맨 뒤로 옮긴다.
- 원소를 옮기는 동시에 `sum1`, `sum2`를 갱신한다.
- 반복문이 끝난 뒤 두 합이 같으면 `answer`, 다르면 `-1`을 반환한다.
