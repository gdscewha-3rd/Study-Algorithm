# https://www.acmicpc.net/problem/10773

st = []

for _ in range(int(input())):
    cmd = int(input())
    if cmd == 0:
        if(st):
            st.pop()
    else:
        st.append(cmd)

print(sum(st))
