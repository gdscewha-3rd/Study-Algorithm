#220522
#백준 2667 단지번호붙이기
#https://www.acmicpc.net/problem/2667

#  덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수
#  음수 % 양수 = 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다


import sys
from itertools import permutations

def solution(num, op):
    maxnum = -1e9
    minnum = 1e9
    n = len(op)
  
    for case in permutations(op, n):
        total = num[0]
        for i in range(1, n+1):
            if case[i - 1] == 1:
                total += num[i]
            elif case[i - 1] == 2:
                total -= num[i]
            elif case[i - 1] == 3:
                total *= num[i]
            elif case[i - 1] == 4:
                total = int(total / num[i])

        if total > maxnum:
            maxnum = total
        if total < minnum:
            minnum = total

    return maxnum, minnum

input = sys.stdin.readline
n = int(input())
num = list(map(int, input().split()))
count = list(map(int, input().split()))
op = []
for i in range(count[0]):
    op.append(1)
for i in range(count[1]):
    op.append(2)
for i in range(count[2]):
    op.append(3)
for i in range(count[3]):
    op.append(4)
minresult = 0
maxresult = 0
maxresult, minresult = solution(num, op)
print(maxresult)
print(minresult)