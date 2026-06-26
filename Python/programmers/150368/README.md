# Programmers 150368 - 이모티콘 할인행사

## 문제 설명
[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/150368)

이모티콘 할인행사에서 다음 목표를 최대한 달성하는 할인율 조합을 찾는 문제입니다.
1. 이모티콘 플러스 서비스 가입자를 최대한 늘리는 것.
2. 이모티콘 판매액을 최대한 늘리는 것.

할인율은 10%, 20%, 30%, 40% 중 하나로 설정됩니다.

## 아이디어
- 이모티콘의 개수가 최대 7개로 매우 적으므로, 가능한 모든 할인율 조합을 탐색하는 **완전 탐색(Brute Force)** 접근이 가능합니다.
- `itertools.product`를 사용하여 각 이모티콘에 대해 4가지 할인율(10, 20, 30, 40)이 적용되는 모든 경우의 수를 구합니다.

## 시간복잡도
- 이모티콘의 개수를 $M$, 사용자의 수를 $N$이라 할 때:
- 가능한 할인율 조합의 수: $4^M$ (최대 $4^7 = 16,384$)
- 각 조합에 대해 모든 사용자의 구매 여부를 판단하는 시간: $O(N \times M)$
- 전체 시간복잡도: $O(4^M \times N \times M)$
- $M=7, N=100$일 때 약 110만 번의 연산으로 충분히 제한 시간 내에 해결 가능합니다.

## 풀이 과정
1. `itertools.product`를 이용해 가능한 모든 할인율 조합(`discounts`)을 생성합니다.
2. 각 할인율 조합에 대해 다음을 수행합니다:
    - 각 사용자별로 할인율이 자신의 기준 이상인 이모티콘을 모두 구매합니다.
    - 구매 합계액이 자신의 기준 금액 이상이면 이모티콘 플러스에 가입시키고(`register += 1`), 그렇지 않으면 판매액에 더합니다(`money += user_money`).
3. 각 조합의 결과(가입자 수, 판매액)를 리스트에 담습니다.
4. 가입자 수 내림차순, 판매액 내림차순으로 정렬하여 가장 첫 번째 요소를 반환합니다.

## 코드 설명
```python
from itertools import product

def solution(users, emoticons):
    answer = []
    ratios = [10, 20, 30, 40]
    # 모든 할인율 조합 생성
    discounts = list(product(ratios, repeat=len(emoticons)))
    
    for dis in discounts :
        register, money = 0, 0
        for u in users:
            user_money = 0
            for i, dis_i in enumerate(dis) :
                # 사용자의 기준 할인율 이상인 경우만 구매
                if dis_i >= u[0] :
                    user_money += emoticons[i] * ((100 - dis_i) / 100)
            
            # 기준 금액 이상이면 서비스 가입, 아니면 매출에 합산
            if user_money >= u[1] :
                register += 1
            else :
                money += user_money
        answer.append((register, money))
    
    # 가입자 수(우선), 판매액 순으로 정렬
    answer.sort(key = lambda x : (-x[0], -x[1]))
        
    return answer[0]
```
