import math
n, x = map(int, input().split())
a= list(map(int, input().split()))
ans= a[0]
for i in range(1,n):
    ans = math.gcd(ans, a[i])
if x % ans==0:
    print("YES")
else:
    print("NO")
Python

