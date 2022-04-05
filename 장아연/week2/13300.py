# 백준 13300 : https://www.acmicpc.net/problem/13300


N, M = map(int, input().split())
#print(N, M)
room = [[0]*2 for _ in range(6)]
# print(room)
res = 0

for _ in range(N):
    s, y = map(int, input().split())
    #print(" y : ", y-1, "s : ", s)
    room[y-1][s] += 1
# print(room)

for i in room:
    for j in i:
        if j % M != 0:
            res += 1
        res += (j // M)


print(res)
