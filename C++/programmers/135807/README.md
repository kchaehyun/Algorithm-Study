# Programmers 135807 - 숫자 카드 나누기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/135807)
- 철수와 영희가 가진 숫자 카드가 각각 `arrayA`, `arrayB`에 담겨 있다.
- 다음 두 조건 중 하나를 만족하는 가장 큰 양의 정수 `a`를 구한다.
  - `arrayA`의 모든 수를 나눌 수 있고, `arrayB`의 어떤 수도 나눌 수 없는 수
  - `arrayB`의 모든 수를 나눌 수 있고, `arrayA`의 어떤 수도 나눌 수 없는 수
- 조건을 만족하는 수가 없다면 `0`을 반환한다.

## 아이디어
- 한 배열의 모든 수를 나눌 수 있는 가장 큰 수는 그 배열 전체의 최대공약수이다.
- 따라서 첫 번째 조건의 후보는 `arrayA`의 최대공약수 `gcdA`, 두 번째 조건의 후보는 `arrayB`의 최대공약수 `gcdB`이다.
- `gcdA`가 `arrayB`의 원소 중 하나라도 나눈다면 첫 번째 조건을 만족하지 못하므로 후보에서 제외한다.
- 같은 방법으로 `gcdB`가 `arrayA`의 원소 중 하나라도 나누면 후보에서 제외한다.
- 유효하지 않은 후보는 `0`으로 바꾸고, 두 후보 중 더 큰 값을 반환한다.

## 풀이 과정
1. `arrayA`의 모든 원소에 대해 최대공약수를 구해 `gcdA`에 저장한다.
2. `arrayB`의 모든 원소에 대해 최대공약수를 구해 `gcdB`에 저장한다.
3. `arrayB`를 순회하며 `gcdA`로 나누어떨어지는 원소가 있는지 확인한다.
4. 하나라도 나누어떨어진다면 `gcdA`를 `0`으로 만든다.
5. `arrayA`를 순회하며 `gcdB`로 나누어떨어지는 원소가 있는지 확인한다.
6. 하나라도 나누어떨어진다면 `gcdB`를 `0`으로 만든다.
7. `gcdA`와 `gcdB` 중 더 큰 값을 반환한다.

## 코드 설명
```cpp
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int maxA = 0, maxB = 0;
    int size = arrayA.size();
    int gcdA = arrayA[0], gcdB = arrayB[0];
    for(int i = 1 ; i < size ; ++i){
        gcdA = gcd(gcdA, arrayA[i]);
        gcdB = gcd(gcdB, arrayB[i]);
    }
    
    bool possible = true;
    for(int i = 0 ; i < size ; ++i) {
        if(!(arrayB[i] % gcdA)) {
            possible = false;
            break;
        }
    }
    if(!possible) gcdA = 0;
    
    possible = true;
    for(int i = 0 ; i < size ; ++i) {
        if(!(arrayA[i] % gcdB)) {
            possible = false;
            break;
        }
    }
    if(!possible) gcdB = 0;
    return max(gcdA,gcdB);
}
```
- `gcdA`, `gcdB`는 각 배열의 모든 원소에 대한 최대공약수이다.
- `!(arrayB[i] % gcdA)`는 `arrayB[i]`가 `gcdA`로 나누어떨어진다는 의미이다.
- 상대 배열에서 후보로 나누어떨어지는 원소를 발견하면 더 확인할 필요가 없으므로 즉시 반복문을 종료한다.
- 조건을 만족하지 못한 후보를 `0`으로 바꾸면 마지막에 `max()`만으로 정답을 구할 수 있다.
- `answer`, `maxA`, `maxB`는 현재 풀이에서 사용되지 않는 변수이므로 제거해도 결과에 영향을 주지 않는다.

## 시간복잡도
- 두 배열의 길이를 `N`, 카드에 적힌 수의 최댓값을 `V`라고 할 때, 최대공약수를 구하는 데 O(N log V)가 걸린다.
- 상대 배열의 원소가 후보로 나누어떨어지는지 확인하는 데 O(N)이 걸리므로 전체 시간복잡도는 O(N log V)이다.
- 입력 배열을 제외한 추가 공간복잡도는 O(1)이다.
