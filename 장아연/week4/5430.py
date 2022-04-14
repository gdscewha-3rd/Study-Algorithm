# https://www.acmicpc.net/problem/5430

from collections import deque
import sys
input = sys.stdin.readline

N = int(input())

for _ in range(N):
    cmd = list(input())
    M = int(input())
    arr = input().strip()[1:-1]
    if arr:
        que = deque(list(map(int, arr.split(","))))
    flag = True
    if M:
        for i in cmd:
            # print(i, que)s
            if i == "R":
                que.reverse()
            elif i == "D":
                if not(que):
                    print("error")
                    flag = False
                    break
                else:
                    que.popleft()
    else:
        flag = False
        print("error")
    if flag:
        print(list(que))
