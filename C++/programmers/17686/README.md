# Programmers 17686 - 파일명 정렬

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/17686)
- 파일명은 `HEAD`, `NUMBER`, `TAIL` 세 부분으로 나눌 수 있다.
- `HEAD`는 숫자가 아닌 문자로 이루어져 있고, `NUMBER`는 1글자 이상 5글자 이하의 연속된 숫자이다.
- 파일명은 먼저 `HEAD`를 기준으로 사전순 정렬하되, 대소문자는 구분하지 않는다.
- `HEAD`가 같으면 `NUMBER`를 정수로 변환한 값을 기준으로 오름차순 정렬한다.
- `HEAD`와 `NUMBER`가 모두 같으면 입력된 순서를 유지한다.

## 아이디어
- 각 파일명을 정렬할 때 필요한 `HEAD`와 `NUMBER`로 파싱한다.
- 처음 숫자가 나오는 위치 전까지를 `HEAD`로 사용한다.
- 숫자가 시작된 뒤에는 최대 5자리까지만 `NUMBER`로 사용한다.
- `HEAD`는 모두 소문자로 바꿔 대소문자를 구분하지 않고 비교한다.
- `HEAD`와 `NUMBER`가 모두 같을 때 기존 순서를 유지해야 하므로 `stable_sort`를 사용한다.

## 시간복잡도
- 파일 개수를 `N`, 파일명 최대 길이를 `L`이라 하면 비교 한 번에 파싱과 소문자 변환으로 `O(L)`이 걸린다.
- 정렬에는 `O(N log N)`번의 비교가 필요하므로 전체 시간복잡도는 `O(N log N * L)`이다.

## 풀이 과정
1. 파일명에서 처음 숫자가 나오는 위치를 찾는다.
2. 해당 위치 전까지의 문자열을 `HEAD`로 저장한다.
3. 숫자가 시작된 위치부터 최대 5자리까지 연속된 숫자를 읽는다.
4. 읽은 숫자 문자열을 정수로 변환해 `NUMBER`로 저장한다.
5. 두 파일명의 `HEAD`를 소문자로 변환한 뒤 비교한다.
6. `HEAD`가 다르면 `HEAD`가 작은 파일명을 앞에 둔다.
7. `HEAD`가 같고 `NUMBER`가 다르면 `NUMBER`가 작은 파일명을 앞에 둔다.
8. 둘 다 같으면 비교 결과를 `false`로 반환해 `stable_sort`가 기존 순서를 유지하게 한다.

## 코드 설명
```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>

using namespace std;

pair<string,int> parsing(string file) {
    int start = 0;
    while(start < file.size() && !isdigit(file[start])) ++start;
    int end = start;
    while(end < file.size() && isdigit(file[end]) && end < start + 5) ++end;
    string head = file.substr(0, start);
    int number = stoi(file.substr(start, end-start));
    return {head, number};
}

bool cmp(string a, string b) {
    auto [headA, numA] = parsing(a);
    auto [headB, numB] = parsing(b);
    
    for(char& c : headA) c = tolower(c);
    for(char& c : headB) c = tolower(c);
    
    if(headA != headB) return headA < headB;
    if(numA != numB) return numA < numB;
    return false;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}
```
- `parsing`은 파일명에서 정렬에 필요한 `HEAD`와 `NUMBER`만 추출한다.
- `start`는 첫 번째 숫자가 나오는 인덱스이다.
- `end`는 `NUMBER`가 끝나는 인덱스이며, 문제 조건에 맞게 최대 5자리까지만 이동한다.
- `stoi`를 사용해 `NUMBER` 문자열을 정수로 변환하므로 앞의 `0`은 자연스럽게 무시된다.
- `cmp`는 두 파일의 `HEAD`를 소문자로 변환한 뒤 먼저 비교한다.
- `HEAD`가 같으면 정수로 변환한 `NUMBER`를 비교한다.
- 두 기준이 모두 같으면 `false`를 반환하고, `stable_sort`가 입력 순서를 보존한다.
