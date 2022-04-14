# https://www.acmicpc.net/problem/2164

from collections import deque
import sys
input = sys.stdin.readline


N = int(input())
que = deque([])
for i in range(N):
    que.append(i+1)

while len(que) > 1:
    que.popleft()
    que.append(que.popleft())
print(que.pop())
