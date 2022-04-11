# https://www.acmicpc.net/problem/2493

N = int(input())
arr = list(map(int, input().split()))
res = []


for idx, i in enumerate(arr):
    #print("idx : ", idx, "i : ", i)
    ans = 0
    for j in range(idx-1, -1, -1):
        #print("j : ", j, "arr[j] : ", arr[j])
        if i <= arr[j]:
            ans = j+1
            break
    res.append(ans)
print(*res)
