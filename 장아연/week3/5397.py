from sys import stdin


for _ in range(int(input())):
    string = stdin.readline().strip()
    st_l, st_r = [], []
    for i in string:
        if i == "-":
            if st_l:
                st_l.pop()
        elif i == "<":
            if st_l:
                st_r.append(st_l.pop())
        elif i == ">":
            if st_r:
                st_l.append(st_r.pop())
        else:
            st_l.append(i)
        # print("st_l", st_l)
        # print("st_r", st_r)

    print("".join(st_l+list(reversed(st_r))))
