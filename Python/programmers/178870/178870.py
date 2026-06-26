def solution(sequence, k):
    answer = []
    left = 0
    min_len = float('inf')
    current_sum = 0
    for right in range(len(sequence)) :
        current_sum += sequence[right]
        while current_sum > k :
            current_sum -= sequence[left]
            left += 1
        if current_sum == k and right-left < min_len:
            answer = [left, right]
            min_len = right-left  
            
    return answer

print(solution([1, 2, 3, 4, 5], 7))