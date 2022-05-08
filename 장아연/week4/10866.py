from collections import deque
import sys

input = sys.stdin.readline

que = deque([])

N = int(input())

for _ in range(N):
    cmd = input().split()
    if cmd[0] == "push_front":
        que.appendleft(int(cmd[-1]))
    elif cmd[0] == "push_back":
        que.append(int(cmd[-1]))
    elif cmd[0] == "pop_front":
        if (que):
            print(que.popleft())
        else:
            print(-1)
    elif cmd[0] == "pop_back":
        if (que):
            print(que.pop())
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
