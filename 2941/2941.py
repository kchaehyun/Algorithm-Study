import sys
input = sys.stdin.readline

word = input().strip()

### 풀이 1
# croatian = ['c=', 'c-', 'd-', 'lj', 'nj', 's=', 'z=']
# i = 0
# cnt = 0
# while i < len(word) :
#     if word[i:i+3] == 'dz=' :
#         i += 3
#     elif word[i:i+2] in croatian :
#         i += 2
#     else :
#         i += 1
#     cnt += 1

# print(cnt)

### 풀이 2
croatian = ['dz=', 'c=', 'c-', 'd-', 'lj', 'nj', 's=', 'z=']
for c in croatian :
    word = word.replace(c,'q')
print(len(word))