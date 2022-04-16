# https://www.acmicpc.net/problem/3986

import sys
input = sys.stdin.readline

N = int(input())
res = 0

for _ in range(N):
    stack = []
    string = input().rstrip()
    for i in string:
        if stack and stack[-1] == i:
            stack.pop()
        else:
            stack.append(i)
    if not(stack):
        res += 1

print(res)
