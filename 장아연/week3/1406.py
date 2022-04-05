from sys import stdin

st_l = list(stdin.readline().strip())
st_r = []


for _ in range(int(input())):
    cmd = stdin.readline().strip()
    # print(cmd)
    if (cmd[0] == "D"):
        if (st_r):
            st_l.append(st_r.pop())
    elif cmd[0] == "L":
        if st_l:
            st_r.append(st_l.pop())
    elif cmd[0] == "B":
        if st_l:
            st_l.pop()
    else:
        st_l.append(cmd[-1])
    # print("###st_r", st_r)
    # print("###st_l", st_l)
print("".join(st_l+list(reversed(st_r))))
