# https://www.acmicpc.net/problem/1021

from collections import deque
import sys
input = sys.stdin.readline
N, M = map(int, input().split())
arr = list(map(int, input().split()))
que = deque(list(range(1, N+1)))
#print(N, M, list(que), arr)
res = 0


for i in arr:
    if que.index(i) < len(que)-que.index(i):
        while True:

            if i == que[0]:

                que.popleft()

                break
            else:

                res += 1
                que.append(que.popleft())
    else:

        while True:
            if i == que[0]:

                que.popleft()
                break
            else:

                res += 1
                que.appendleft(que.pop())

print(res)
