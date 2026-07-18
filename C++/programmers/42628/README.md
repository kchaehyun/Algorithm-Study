# Programmers 42628 - 이중우선순위큐

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42628)
- 문자열 배열 `operations`에는 숫자 삽입과 최댓값 또는 최솟값 삭제 명령이 주어진다.
- `I 숫자`는 해당 숫자를 큐에 삽입한다.
- `D 1`은 큐에서 최댓값을 삭제하고, `D -1`은 최솟값을 삭제한다.
- 큐가 비어 있을 때 삭제 명령이 주어지면 해당 명령은 무시한다.
- 모든 명령을 처리한 뒤 `[최댓값, 최솟값]`을 반환한다.
- 큐가 비어 있다면 `[0, 0]`을 반환한다.

## 아이디어
- 최댓값과 최솟값을 모두 빠르게 찾기 위해 최대 힙과 최소 힙을 함께 사용한다.
- 같은 값이 여러 번 삽입될 수 있으므로 각 원소를 `{값, 삽입 명령의 인덱스}` 형태로 두 힙에 저장한다.
- `valid[i]`는 `i`번째 명령으로 삽입한 원소가 아직 유효한지를 나타낸다.
- 한 힙에서 원소를 삭제할 때 해당 원소의 `valid` 값만 `false`로 바꾼다.
- 다른 힙에 남아 있는 삭제된 원소는 힙의 맨 위에 도달했을 때 제거하는 지연 삭제 방식을 사용한다.
- 모든 명령을 처리한 후 두 힙의 무효한 원소를 정리하고 최댓값과 최솟값을 구한다.

## 시간복잡도
- 각 원소는 두 힙에 한 번씩 삽입되고 각 힙에서 최대 한 번씩 제거된다.
- 힙의 삽입과 삭제에는 O(log N)이 필요하므로 전체 시간복잡도는 O(N log N)이다.
- 두 힙과 유효 여부 배열을 사용하므로 공간복잡도는 O(N)이다.

## 풀이 과정
1. 최대 힙 `maxHeap`, 최소 힙 `minHeap`, 유효 여부 배열 `valid`를 만든다.
2. 삽입 명령이면 `{숫자, 명령 인덱스}`를 두 힙에 넣고 `valid[i]`를 `true`로 설정한다.
3. 최댓값 삭제 명령이면 최대 힙 위의 무효한 원소를 먼저 제거한다.
4. 최대 힙에 유효한 원소가 남아 있다면 해당 원소의 `valid`를 `false`로 바꾸고 힙에서 제거한다.
5. 최솟값 삭제 명령도 최소 힙에서 같은 방식으로 처리한다.
6. 모든 명령이 끝나면 두 힙 위에 남은 무효한 원소를 제거한다.
7. 힙이 비어 있으면 `{0, 0}`, 그렇지 않으면 `{최댓값, 최솟값}`을 반환한다.

## 코드 설명
```cpp
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<pair<int,int>> maxHeap;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    vector<bool> valid(operations.size(), false);
    for(int i = 0 ; i < operations.size() ; ++i) {
        char command = operations[i][0];
        int num = stoi(operations[i].substr(2));
        if(command == 'I') {
            maxHeap.push({num, i});
            minHeap.push({num, i});
            valid[i] = true;
            continue;
        }
        if(num == 1) {
            while(!maxHeap.empty() && !valid[maxHeap.top().second]) maxHeap.pop();
            if(!maxHeap.empty()) {
                valid[maxHeap.top().second] = false;
                maxHeap.pop();
            }
        }
        else {
            while(!minHeap.empty() && !valid[minHeap.top().second]) minHeap.pop();
            if(!minHeap.empty()) {
                valid[minHeap.top().second] = false;
                minHeap.pop();
            }
        }
    }
    while(!maxHeap.empty() && !valid[maxHeap.top().second]) maxHeap.pop();
    while(!minHeap.empty() && !valid[minHeap.top().second]) minHeap.pop();
    
    if(maxHeap.empty() || minHeap.empty()) return {0,0};
    return {maxHeap.top().first, minHeap.top().first};
}
```
- `maxHeap`은 현재 원소 중 최댓값을, `minHeap`은 최솟값을 빠르게 찾는다.
- 각 힙의 원소에 삽입 인덱스를 함께 저장해 두 힙의 동일한 원소를 구분한다.
- `valid[index]`가 `false`인 원소는 다른 힙에서 이미 삭제된 원소이므로 사용할 수 없다.
- 삭제 명령 전에 `while`문으로 힙 위의 무효한 원소를 정리한다.
- 마지막에도 두 힙을 정리해야 실제로 남아 있는 최댓값과 최솟값을 정확하게 반환할 수 있다.
