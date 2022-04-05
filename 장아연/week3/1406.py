st_l = list(input())
st_r = []


for _ in range(int(input())):
    cmd = list(input().split())
    if (cmd[0] == "D") and (st_r):
        st_l.append(st_r.pop())
    elif cmd[0] == "L" and st_l:
        st_r.append(st_l.pop())
    elif cmd[0] == "B" and st_l:
        st_l.pop()
    else:
        st_l.append(cmd[-1])

print("".join(st_l+list(reversed(st_r))))
