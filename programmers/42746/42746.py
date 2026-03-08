def solution(numbers):
    answer = ''
    numbers = list(map(str, numbers))
    numbers.sort(key = lambda x: x*3, reverse=True)
    answer = int("".join(map(str,numbers)))
    if answer != 0 :
        return str(answer)
    else:
        return "0"