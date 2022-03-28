# 2022.03.28
# 문제 : 백준 108080 : https://www.acmicpc.net/problem/10808

N = input()
# print(ord("z")-ord("a"))
res = [0]*(ord("z")-ord("a")+1)

for i in N:
    # print(ord(i)-ord("a"))
    res[ord(i)-ord("a")] += 1

for i in res:
    print(i, end=" ")
