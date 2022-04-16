# https://www.acmicpc.net/problem/10799

import sys
input = sys.stdin.readline

stack = []
res = 0
string = input().rstrip()
for i in range(len(string)):
    if string[i] == "(":
        stack.append(i)
        # print("더하기")
    else:
        stack.pop()
        if string[i-1] == "(":  # () 짝지어지는 경우 : 레이저 임
            res += len(stack)
            #print("길이만큼", len(stack))
        else:  # )) 인 경우 : 나무 도막의 끝임
            res += 1
            #print("1 더하기")

print(res)
