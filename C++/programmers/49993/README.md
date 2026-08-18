# Programmers 49993 - 스킬트리

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/49993)
- 선행 스킬 순서 `skill`과 여러 개의 스킬트리 `skill_trees`가 주어진다.
- 선행 스킬 순서에 포함되지 않은 스킬은 순서와 관계없이 배울 수 있다.
- 선행 스킬이 필요한 경우에는 반드시 앞에 있는 스킬을 먼저 배워야 한다.
- 주어진 스킬트리 중 가능한 스킬트리의 개수를 반환한다.

## 아이디어
- 각 스킬트리에서 `skill`에 포함된 스킬만 남기면 선행 스킬의 실제 학습 순서를 확인할 수 있다.
- 예를 들어 선행 스킬 순서가 `CBD`일 때 `BACDE`에서 관련 스킬만 추리면 `BCD`가 된다.
- 올바른 학습 순서는 `skill`의 앞부분부터 차례대로 이어져야 한다.
- 따라서 추린 문자열이 `skill`의 접두사라면 가능한 스킬트리이다.
- 관련 스킬을 하나도 배우지 않은 경우에도 빈 문자열은 모든 문자열의 접두사이므로 올바르게 처리된다.

## 시간복잡도
- `skill`의 길이를 `S`, 모든 스킬트리의 문자 수 합을 `N`이라고 하면 각 문자가 `skill`에 포함되는지 선형 탐색하므로 O(N × S)이다.

## 풀이 과정
1. 가능한 스킬트리의 개수를 저장할 `answer`를 0으로 초기화한다.
2. `skill_trees`의 각 스킬트리 `st`를 순회한다.
3. `st`의 문자 중 `skill`에 포함된 문자만 `word`에 추가한다.
4. `word`가 `skill`의 접두사인지 확인한다.
5. 접두사라면 선행 스킬 순서를 지킨 것이므로 `answer`를 1 증가시킨다.
6. 모든 스킬트리를 확인한 뒤 `answer`를 반환한다.

## 코드 설명
```cpp
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(string st : skill_trees) {
        string word;
        for(char c : st) {
            if(find(skill.begin(), skill.end(), c) != skill.end()) word += c;
        }
        if(skill.starts_with(word)) ++answer;
    }
    return answer;
}
```
- `find(skill.begin(), skill.end(), c)`는 현재 스킬 `c`가 선행 스킬 순서에 포함되어 있는지 확인한다.
- 선행 스킬 순서에 포함된 문자만 `word`에 추가하여 비교에 필요 없는 스킬을 제거한다.
- `skill.starts_with(word)`는 `word`가 `skill`의 처음부터 같은 순서로 이어지는지 검사한다.
- 검사 결과가 참이면 필요한 선행 스킬을 빠뜨리거나 순서를 어긴 경우가 아니므로 `answer`를 증가시킨다.
- `starts_with`는 C++20부터 제공되는 문자열 함수이다.
