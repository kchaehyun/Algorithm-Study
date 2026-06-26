import sys
input = sys.stdin.readline

p, m = map(int, input().split())

levels = []
rooms = []

first, f_nickname = map(str, input().split())
levels.append(int(first))
rooms.append([(first, f_nickname)]) 

for _ in range(p-1) :
    l, n = map(str, input().split())
    l = int(l)
    is_join = False
    for i,level in enumerate(levels) :
        if level-10 <= l <= level+10 and len(rooms[i]) < m :
            rooms[i].append((str(l), n))
            is_join = True
            break
    if not is_join :
        rooms.append([(str(l),n)])
        levels.append(l)

for i in range(len(rooms)) :
    if len(rooms[i]) == m :
        print("Started!")
    else :
        print("Waiting!")
    rooms[i] = sorted(rooms[i], key=lambda x:x[1])
    for r in rooms[i] :
        print(' '.join(r))