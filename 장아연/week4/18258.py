# https://www.acmicpc.net/problem/18258

from collections import deque
import sys
input = sys.stdin.readline

N = int(input())
que = deque([])

for _ in range(N):
    cmd = input().split()
    # print(cmd)
    if cmd[0] == "push":
        que.append(cmd[-1])
    elif cmd[0] == "pop":
        if que:
            print(que.popleft())
        else:
            print(-1)
    elif cmd[0] == "size":
        print(len(que))
    elif cmd[0] == "empty":
        if not(que):
            print(1)
        else:
            print(0)
    elif cmd[0] == "front":
        if que:
            print(que[0])
        else:
            print(-1)
    elif cmd[0] == "back":
        if que:
            print(que[-1])
        else:
            print(-1)
