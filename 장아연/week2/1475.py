# 22.03.29
# 문제 백준 1475 : https://www.acmicpc.net/problem/1475

N = input()
arr = [0]*10
# print(arr)

for i in N:
    if (int(i) == 9) or (int(i) == 6):
        if arr[6] <= arr[9]:
            arr[6] += 1
        else:
            arr[9] += 1
    else:
        arr[int(i)] += 1

# print(arr)
print(max(arr))
