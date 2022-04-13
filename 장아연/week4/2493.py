# https://www.acmicpc.net/problem/2493

import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
# print(arr)
stack = []
res = [0]*N

for i in range(N):
    while stack and arr[stack[-1]] < arr[i]:
        stack.pop()
    if stack:
        res[i] = stack[-1]+1
    stack.append(i)

print(" ".join(map(str, res)))
