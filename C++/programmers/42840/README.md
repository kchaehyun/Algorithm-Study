# Programmers 42840 - 모의고사

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42840)
- 1번, 2번, 3번 수포자가 각각 정해진 방식으로 문제를 찍는다.
- 정답 배열 `answers`가 주어졌을 때 가장 많은 문제를 맞힌 사람을 찾아 반환한다.
- 가장 높은 점수를 받은 사람이 여러 명이면 번호가 작은 순서대로 모두 반환한다.

## 아이디어
- 각 수포자의 찍기 패턴은 일정하게 반복된다.
- 세 사람의 패턴을 `patterns` 벡터에 저장한다.
- `answers`를 순회하면서 현재 문제 번호를 각 패턴의 길이로 나눈 나머지를 이용해 반복 위치를 구한다.
- 패턴의 값과 실제 정답이 같으면 해당 수포자의 점수를 증가시킨다.
- 세 점수 중 최댓값을 구한 뒤, 최댓값과 같은 점수를 가진 수포자의 번호를 `answer`에 넣는다.

## 시간복잡도
- 정답 개수를 `N`이라고 하면 세 명의 답안만 비교하므로 O(N)

## 풀이 과정
1. 수포자별 점수를 저장할 `scores` 배열을 0으로 초기화한다.
2. 세 수포자의 반복 패턴을 `patterns`에 저장한다.
3. `answers`를 처음부터 끝까지 순회한다.
4. 각 문제마다 세 수포자의 현재 패턴 값과 정답을 비교한다.
5. 정답이 일치하면 해당 수포자의 점수를 1 증가시킨다.
6. 세 점수 중 가장 큰 값을 `max_score`에 저장한다.
7. 점수가 `max_score`와 같은 수포자의 번호를 `answer`에 추가한다.
8. `answer`를 반환한다.

## 코드 설명
```cpp
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int scores[3] = {0};
    int max_score = 0;
    vector<vector<int>> patterns = {{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
    
    for(int n = 0 ; n < answers.size() ; ++n)
        for (int i = 0 ; i < 3 ; ++i)
            if (patterns[i][n%patterns[i].size()] == answers[n]) scores[i]++;
    
    for(int i = 0 ; i < 3 ; ++i)
        if (max_score < scores[i]) max_score = scores[i];   
    
    for(int i = 0 ; i < 3 ; ++i)
        if (scores[i] == max_score) answer.push_back(i+1);

    return answer;
}
```
- `patterns`는 각 수포자의 반복되는 답안 패턴을 저장한다.
- `n % patterns[i].size()`는 현재 문제에서 해당 수포자가 찍는 답의 위치를 구한다.
- `patterns[i][n % patterns[i].size()] == answers[n]`이면 해당 수포자가 문제를 맞힌 것이다.
- `scores[i]++`로 맞힌 개수를 증가시킨다.
- `max_score`에 세 수포자 점수 중 가장 높은 점수를 저장한다.
- 마지막 반복문은 1번 수포자부터 확인하므로 동점자가 있을 때 번호 오름차순으로 `answer`에 들어간다.
