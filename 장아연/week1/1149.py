# https://www.acmicpc.net/problem/1149

# S(k,r)=cur R + min(S(k-1,b),S(k-1,g))


N = int(input())

arr = [list(map(int, input().split()))for _ in range(N)]
R = G = B = 0


for i in range(len(arr)):
    if i == 0:
        res = [arr[i]]

    else:
        pR, pG, pB = res[i-1]
        cR, cG, cB = arr[i]
        R = cR+min(pB, pG)
        B = cB+min(pR, pG)
        G = cG+min(pR, pB)
        res.append([R, G, B])
    # print(res)
print(min(res[-1]))
