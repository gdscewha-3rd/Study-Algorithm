# https://www.acmicpc.net/problem/1926
# 22.05.02


from collections import deque
import sys
input = sys.stdin.readline


N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
visited = [[False]*M for _ in range(N)]
cnt, res = 0, 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

#print(N, M, graph, visited, cnt, res)


def bfs(i, j):
    area = 1
    visited[i][j] = True
    que = deque([(i, j)])
    while que:
        x, y = que.popleft()
        for k in range(4):
            nx, ny = x+dx[k], y+dy[k]
            if 0 <= nx < N and 0 <= ny < M:
                if graph[nx][ny] == 1 and not visited[nx][ny]:
                    area += 1
                    visited[nx][ny] = True
                    que.append((nx, ny))
    return area


for i in range(N):
    for j in range(M):
        if graph[i][j] == 1 and not visited[i][j]:
            cnt += 1
            visited[i][j] = True
            res = max(res, bfs(i, j))

print(cnt)
print(res)
