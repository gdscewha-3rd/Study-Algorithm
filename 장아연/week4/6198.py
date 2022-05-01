# https://www.acmicpc.net/problem/6198

import sys
input = sys.stdin.readline
N = int(input())
arr = [int(input()) for _ in range(N)]
# print(arr)
stack = []
res = [0]*N


for i in range(N):
    while stack and arr[stack[-1]] <= arr[i]:
        stack.pop()
    stack.append(i)
    if stack:
        # print(stack)
        res[stack[-1]] = len(stack)-1

print(sum(res))
