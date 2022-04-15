# https://www.acmicpc.net/problem/5430

from collections import deque
import sys
input = sys.stdin.readline

N = int(input())

for _ in range(N):
    cmd = input().strip()
    M = int(input())
    flag = True
    que = deque(input().strip()[1:-1].split(','))
    R_cnt = 0
    if M == 0:
        que = deque()
    for i in cmd:
        if i == "R":
            R_cnt += 1
        elif i == "D":
            if len(que) == 0:
                print("error")
                flag = False
                break
            else:
                if R_cnt % 2 == 0:
                    que.popleft()
                else:
                    que.pop()
    if not(flag):
        continue
    else:
        if R_cnt % 2 != 0:
            que.reverse()
        print('[' + ",".join(que) + ']')
