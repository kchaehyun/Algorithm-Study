# ------- 풀이 1 -------
import sys
input = sys.stdin.readline

N = int(input())
ans = 0
possible = False
num1, num2 = 0, 0

for a in range(1667):
    for b in range(1000):
        if (5*a + 3*b) == N:
            num1 = a
            num2 = b
            possible = True
            break
        
if possible:
    print(num1+num2)

else:
    print(-1)

# ------- 풀이 2 -------

### 최대한 5kg을 많이 써야함
### 5로 나눠질때까지 3을 빼주면 됨
import sys
input = sys.stdin.readline

N = int(input())
ans = 0
possible = False

while N > 0:
    if N % 5 > 0:
        N -= 3
        ans += 1
    if N % 5 == 0 :
        ans += N//5
        possible = True
        break

if possible : 
    print(ans)
else:
    print(-1)