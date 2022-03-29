# 문제 : 백준 3273 : https://www.acmicpc.net/problem/3273

#from itertools import combinations

N = int(input())
arr = sorted(list(map(int, input().split())))

M = int(input())
left, right = 0, N-1
res = 0

while left < right:
    #print(arr[left], arr[right])
    temp = arr[left]+arr[right]
    # print("###", temp)
    if M == (temp):
        res += 1
        left += 1
    elif M < temp:
        right -= 1
    else:
        left += 1

print(res)
