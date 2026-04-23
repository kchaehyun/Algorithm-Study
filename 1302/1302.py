import sys
input = sys.stdin.readline

N = int(input())
books = {}
for i in range(N) :
    book = input().strip()
    if book not in books :
        books[book] = 1
    else :
        books[book] += 1

max_cnt = max(books.values())
tmp = []
for k,v in books.items() :
    if v == max_cnt :
        tmp.append(k)
print(sorted(tmp)[0])