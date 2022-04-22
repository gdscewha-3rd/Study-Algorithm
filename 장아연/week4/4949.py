# https://www.acmicpc.net/problem/4949


import sys
input = sys.stdin.readline

while True:
    string = input().rstrip()
    stack = []
    if string == ".":
        #print("점 : 종료")
        break
    for i in string:
        # print(i)
        if i == "(" or i == "[":
            stack.append(i)
        elif i == ")":
            if stack and stack[-1] == "(":
                stack.pop()
            else:
                stack.append(i)
                break
        elif i == "]":
            if stack and stack[-1] == "[":
                stack.pop()
            else:
                stack.append(i)
                break
    if not(stack):
        print("yes")
    else:
        print("no")
