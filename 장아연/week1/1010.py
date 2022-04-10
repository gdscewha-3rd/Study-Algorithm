# 220325
# 백준 1010 : https://www.acmicpc.net/problem/1010
# https://yoonsang-it.tistory.com/33


import math


T = int(input())

for _ in range(T):
    n, m = map(int, input().split())
    ans = math.factorial(m) // (math.factorial(n) * math.factorial(m - n))
    print(ans)
