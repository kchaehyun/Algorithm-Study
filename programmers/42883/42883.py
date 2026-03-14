def solution(number, k):
    stack = [number[0]]
    for n in number[1:] :
        while stack and k > 0 and stack[-1] < n :
            stack.pop()
            k -= 1
        stack.append(n)
    
    if k != 0 :
        return ''.join(map(str,stack[:-k]))
        
    return ''.join(map(str,stack))