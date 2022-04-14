import sys
input = sys.stdin.readline


N = int(input())
arr = [int(input()) for _ in range(N)]
stack = []
res = 0


for h in arr:
    # stack에 현재 사람보다 작은 사람이 있으면 pop하고 answer에 추가
    while stack and stack[-1][0] < h:
        res += stack.pop()[1]

    if stack and stack[-1][0] == h:  # 현재 사람과 키가 같은 사람 있음
        # 현재 같은키보다 왼쪽이 있으므로 -> top과 현재 사람이 볼 수 있으므로 1 추가
        cnt = stack.pop()[1]
        res += cnt
        if stack:
            res += 1
        stack.append([h, cnt+1])
    else:  # 스택이 비어 있거나 현재 사람보다 키가 더 큰 경우
        if stack:
            res += 1
        stack.append([h, 1])

print(res)
