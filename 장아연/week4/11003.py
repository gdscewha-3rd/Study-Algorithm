# https://www.acmicpc.net/problem/11003

from collections import deque
import sys
input = sys.stdin.readline
N, M = map(int, input().split())
arr = list(map(int, input().split()))
que = deque()

for i in range(N):
    while que and que[-1][0] > arr[i]:
        que.pop()
    while que and que[0][1] < i-M+1:
        que.popleft()
    que.append((arr[i], i))
    print(que[0][0], end=" ")
