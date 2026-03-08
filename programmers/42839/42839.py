from math import sqrt
from itertools import permutations

def is_prime(num) :
    if num == 0 or num == 1 :
        return False
    for i in range(2, int(sqrt(num)) + 1) :
        if num % i == 0:
            return False
    return True

def solution(numbers):
    answer = 0
    numbers = list(map(str,numbers))
    arr = set()
    for i in range(len(numbers)) :
        for p in permutations(numbers,i+1) :
            arr.add(int(''.join(p)))
    for x in arr :
        if is_prime(x) :
            answer += 1
    return answer