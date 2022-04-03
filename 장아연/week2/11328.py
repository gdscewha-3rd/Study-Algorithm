# 22.03.29
# 백준 11328 : https://www.acmicpc.net/problem/11328

N = int(input())
res = []
for _ in range(N):
    a, b = input().split()
    if sorted(a) != sorted(b):
        print("Impossible")
    else:
        print("Possible")
