# https://www.acmicpc.net/problem/9012

import sys
input = sys.stdin.readline

N = int(input())

for _ in range(N):
    string = input().rstrip()
    # print(string)
    stack = []
    for i in string:
        # print(i)
        if i == "(":
            stack.append(i)
        else:
            if stack and stack[-1] == "(":
                stack.pop()
            else:
                stack.append(i)
    if not(stack):
        print("YES")
    else:
        print("NO")
