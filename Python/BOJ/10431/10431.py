import sys
input = sys.stdin.readline

P = int(input())

for _ in range(P) :
    nums = list(map(int, input().split()))
    T = nums[0]
    heights = nums[1:]

    cnt = 0
    line = []
    
    for h in heights :
        pos = len(line)
        for i in range(len(line)) :
            if line[i] > h :
                pos = i
                break
        cnt += len(line) - pos
        line.insert(pos, h)

    print(T, cnt)