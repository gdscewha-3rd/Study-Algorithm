# 문제 : 백준 3273 : https://www.acmicpc.net/problem/3273

#from itertools import combinations

N = int(input())
arr = sorted(list(map(int, input().split())))
M = int(input())
res = {}
cnt = 0
# print(arr)

for i in arr:
    if (M-i) <= 0:
        continue
    else:
        if ((M-i) in arr) and i < M-i:
            cnt += 1

# print(res)
print(cnt)
