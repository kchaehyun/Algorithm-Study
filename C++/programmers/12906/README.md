# Programmers 12906 - 같은 숫자는 싫어

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/12906)
- 정수 배열 `arr`에서 연속으로 나타나는 같은 숫자는 하나만 남기고 제거한다.
- 단, 숫자의 순서는 유지해야 한다.

## 아이디어
- 결과 배열 `answer`의 마지막 값과 현재 값을 비교한다.
- `answer`가 비어 있거나, 현재 값이 마지막 값과 다를 때만 추가한다.
- 이렇게 하면 연속된 중복만 제거되고, 떨어져 있는 같은 숫자는 그대로 유지된다.

## 시간복잡도
- O(N)

## 풀이 과정
1. 결과를 저장할 벡터 `answer`를 만든다.
2. `arr`의 원소를 처음부터 끝까지 순회한다.
3. `answer`가 비어 있거나 `answer.back()`이 현재 원소와 다르면 `answer`에 추가한다.
4. 최종 `answer`를 반환한다.

## 코드 설명
```cpp
vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for(int i = 0 ; i < arr.size() ; ++i) {
        if(answer.empty() || answer.back() != arr[i])
            answer.push_back(arr[i]);
    }

    return answer;
}
```
- `answer.back()`은 결과 배열의 마지막 값을 의미한다.
- `answer.empty()` 조건을 먼저 확인해 빈 벡터에서 `back()`을 호출하지 않도록 한다.
- 현재 원소가 직전 저장 값과 다를 때만 추가하므로 연속 중복이 제거된다.
