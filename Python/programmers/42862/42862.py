def solution(n, lost, reserve):
    lost = set(lost)
    reserve = set(reserve)
    inter = lost & reserve
    lost -= inter
    reserve -= inter
    for l in sorted(lost) :
        if l-1 in reserve :
            reserve.remove(l-1)
            lost.remove(l)
            continue
        elif l+1 in reserve :
            reserve.remove(l+1)
            lost.remove(l)
            continue
            
    return n - len(lost)