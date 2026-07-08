# BOJ 1406 - 에디터

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1406)
- 문자열과 명령어가 주어진다.
- 커서는 문장의 맨 앞, 맨 뒤, 문자 사이에 위치할 수 있다.
- 명령어에 따라 커서를 이동하거나, 커서 왼쪽 문자를 삭제하거나, 커서 왼쪽에 문자를 추가한다.
- 모든 명령어를 수행한 뒤 최종 문자열을 출력한다.

## 알고리즘 유형
- 연결 리스트
- 반복자

## 아이디어
- 문자열 중간에서 삽입과 삭제가 자주 일어나므로 `vector`나 `string`으로 처리하면 비효율적이다.
- `list<char>`를 사용하면 커서 위치에서 삽입과 삭제를 O(1)에 처리할 수 있다.
- 커서는 `list<char>::iterator`로 표현한다.
- 커서가 가리키는 위치는 실제 문자 하나가 아니라, 다음 문자가 삽입될 위치로 생각한다.

## 시간복잡도
- 초기 문자열 길이를 `N`, 명령어 개수를 `M`이라고 하면 O(N + M)
- 각 명령어는 커서 이동, 삽입, 삭제를 상수 시간에 처리한다.

## 풀이 과정
1. 입력 문자열의 각 문자를 `list<char>`에 저장한다.
2. 커서를 `editor.end()`로 두어 처음에는 문자열 맨 뒤에 위치시킨다.
3. 명령어를 하나씩 읽으며 처리한다.
4. `L` 명령은 커서가 맨 앞이 아닐 때 왼쪽으로 한 칸 이동한다.
5. `D` 명령은 커서가 맨 뒤가 아닐 때 오른쪽으로 한 칸 이동한다.
6. `B` 명령은 커서가 맨 앞이 아닐 때 커서 왼쪽 문자를 삭제한다.
7. `P x` 명령은 커서 왼쪽에 문자 `x`를 삽입한다.
8. 모든 명령어 처리 후 리스트를 처음부터 끝까지 출력한다.

## 코드 설명
```cpp
list<char> editor;

for(auto c : s) editor.push_back(c);
auto cursor = editor.end();
```
- 입력 문자열을 연결 리스트에 저장한다.
- `cursor`는 현재 커서 위치를 나타내며, 처음에는 문자열 맨 뒤인 `end()`를 가리킨다.

```cpp
case 'L' :
    if(cursor == editor.begin()) continue;
    --cursor;
    break;
```
- 커서가 맨 앞이면 더 이상 왼쪽으로 이동할 수 없다.
- 그렇지 않으면 반복자를 하나 앞으로 이동시킨다.

```cpp
case 'D' :
    if(cursor == editor.end()) continue;
    ++cursor;
    break;
```
- 커서가 맨 뒤이면 더 이상 오른쪽으로 이동할 수 없다.
- 그렇지 않으면 반복자를 하나 뒤로 이동시킨다.

```cpp
case 'B' :
    if(cursor == editor.begin()) continue;
    tmpCursor = cursor;
    --tmpCursor;
    editor.erase(tmpCursor);
    break;
```
- 삭제 대상은 커서가 가리키는 위치가 아니라 커서의 왼쪽 문자이다.
- `tmpCursor`를 커서 위치에서 한 칸 왼쪽으로 옮긴 뒤 해당 문자를 삭제한다.
- `erase`는 삭제된 원소를 제외한 다른 반복자를 무효화하지 않으므로 기존 `cursor`는 계속 사용할 수 있다.

```cpp
case 'P' :
    char x;
    cin >> x;
    editor.insert(cursor, x);
    break;
```
- `insert(cursor, x)`는 `cursor`가 가리키는 위치 바로 앞에 `x`를 삽입한다.
- 문제의 "커서 왼쪽에 문자를 추가"하는 동작과 일치한다.

