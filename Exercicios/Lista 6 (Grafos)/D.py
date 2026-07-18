import sys
from collections import deque
input = sys.stdin.readline
n, m = map(int, input().split())
friends = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    friends[a].append(b)
    friends[b].append(a)
team = [0] * n  
for i in range(n):
    if team[i] == 0:
        q = deque([i])
        team[i] = 1
        while q:
            u = q.popleft()
            for v in friends[u]:
                if team[v] == 0:
                    team[v] = 3 - team[u]
                    q.append(v)
                elif team[v] == team[u]:
                    print("IMPOSSIBLE")
                    exit()
print(*team)
