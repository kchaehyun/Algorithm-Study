from collections import deque

def diff_cnt(a,b) :
    cnt = 0
    for i in range(len(a)) :
        if a[i] != b[i] :
            cnt += 1
    return cnt

def transform(begin,target,words):
    visited = [False]*len(words)
    queue = deque([(begin,0)])
    while queue :
        tmp, step = queue.popleft()
        if tmp == target :
            return step
        for i in range(len(words)) :
            if diff_cnt(tmp,words[i]) == 1 :
                if not visited[i] :
                    visited[i] = True
                    queue.append((words[i],step+1))
    return 0
                

def solution(begin, target, words):
    return transform(begin,target,words)