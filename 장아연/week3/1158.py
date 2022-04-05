from sys import stdin


N, M = map(int, input().split())
#print(N, M)
string = [i+1 for i in range(N)]
ans = []

while string:
    for i in range(M):
        print(i)
        w = string[0]
        string.remove(w)
        if i == M-1:
            ans.append(w)
        else:
            string.append(w)
        print("ans: ", ans)
        print("string : ", string)

print("<", ", ".join(str(i) for i in ans)[:], ">", sep="")
