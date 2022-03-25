# 문제 : https://www.acmicpc.net/problem/1010
# https://lar542.github.io/Python/2019-07-11-python2/


from itertools import combinations

T = int(input())
arr = [list(map(int, input().split())) for _ in range(T)]

# print(arr)

for i in arr:
    i.sort(reverse=True)
    N = list(j for j in range(i[0]))
    print(len(list(combinations(N, i[1]))))
