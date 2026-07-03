# Programmers 42746 - 가장 큰 수

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42746)
- 0 또는 양의 정수가 담긴 배열 `numbers`가 주어진다.
- 배열의 수를 이어 붙여 만들 수 있는 가장 큰 수를 문자열로 반환한다.

## 아이디어
- 숫자를 문자열로 바꾼 뒤, 두 문자열 `a`, `b`의 배치 순서를 비교한다.
- `a`를 앞에 둘지 `b`를 앞에 둘지는 `a + b`와 `b + a` 중 더 큰 문자열을 만들 수 있는 쪽으로 결정한다.
- 예를 들어 `"3"`과 `"30"`은 `"330"`이 `"303"`보다 크므로 `"3"`이 앞에 와야 한다.
- 모든 값이 0인 경우 정렬 후 첫 값이 `"0"`이 되므로 결과는 `"000"`이 아니라 `"0"`으로 반환한다.

## 시간복잡도
- 정렬이 지배적이므로 O(N log N)
- 비교할 때 문자열을 이어 붙이는 비용이 추가되지만, 문제에서 숫자의 길이가 작아 정렬 복잡도로 볼 수 있다.

## 풀이 과정
1. `numbers`의 각 정수를 문자열로 변환해 `nums` 벡터에 저장한다.
2. `a + b > b + a`를 기준으로 내림차순 정렬한다.
3. 정렬 후 첫 번째 값이 `"0"`이면 모든 수가 0이므로 `"0"`을 반환한다.
4. 정렬된 문자열들을 순서대로 이어 붙여 정답을 만든다.

## 코드 설명
```cpp
bool comp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    for (int n : numbers) nums.push_back(to_string(n));
    sort(nums.begin(), nums.end(), comp);
    if (nums[0] == "0") return "0";
    for (string n : nums) answer += n;
    return answer;
}
```
- `comp`는 두 숫자 문자열의 연결 결과를 비교해 더 큰 수가 되는 순서를 정한다.
- `sort(nums.begin(), nums.end(), comp)`로 가장 큰 수를 만들 수 있는 순서로 정렬한다.
- `nums[0] == "0"` 처리는 `["0", "0"]` 같은 입력에서 `"00"` 대신 `"0"`을 반환하기 위한 예외 처리다.
