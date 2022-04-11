import sys
input = sys.stdin.readline
n = int(input())
arr = list(map(int, input().split()))
stack = []  # 수신 가능한 탑
res = [0] * n

for i in range(n):
    while stack and arr[stack[-1]] < arr[i]:
        stack.pop()  # 수신 불가능
    if stack:
        res[i] = stack[-1] + 1
    stack.append(i)
print(' '.join(list(map(str, res))))
