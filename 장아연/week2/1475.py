# 22.03.29
# 문제 백준 1475 : https://www.acmicpc.net/problem/1475

N = input()
arr = [0]*9
# print(arr)

for i in N:
    if (int(i) == 9) or (int(i) == 6):
        arr[6] += 0.5
    else:
        arr[int(i)] += 1
arr[6] = int(arr[6]+0.5)
# print(arr)
print(max(arr))
