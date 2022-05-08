# https://www.acmicpc.net/problem/1874

N = int(input())
arr = [int(input()) for _ in range(N)]
res = []
st = [-1]
idx = 1
flag = True
for i in arr:
    while flag:
        #print(i, st[-1], idx)
        if i != st[-1]:
            if idx <= N:
                res.append("+")
                st.append(idx)
                idx += 1
            else:
                print("NO")
                flag = False
        else:
            st.pop()
            res.append("-")
            break


if flag:
    for i in res:
        print(i)


# print(res)
