from sys import stdin


N, M = map(int, input().split())
#print(N, M)
string = [i+1 for i in range(N)]
ans = []
idx = 0

while string:
    idx += M-1
    if idx >= len(string):
        idx = idx % len(string)

    ans.append(string.pop(idx))

    #print("ans: ", ans)
    #print("string : ", string)

print("<", ", ".join(str(i) for i in ans)[:], ">", sep="")
