# https://www.acmicpc.net/problem/10845


import sys
input = sys.stdin.readline

N = int(input())
que = []

for _ in range(N):
    cmd = input().split()
    # print(cmd)
    if cmd[0] == "push":
        que.append(cmd[-1])
    elif cmd[0] == "pop":
        if que:
            print(que.pop(0))
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
