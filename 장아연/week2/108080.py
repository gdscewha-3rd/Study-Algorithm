# 2022.03.28
# 문제 : 백준 108080 : https://www.acmicpc.net/problem/10808

N = input()
dic = {}
for i in range(ord("a"), ord("z")+1):
    dic[i] = 0

for i in N:
    dic[ord(i)] += 1

for i in dic.values():
    print(i, end=" ")
