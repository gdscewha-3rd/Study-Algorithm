# https://www.acmicpc.net/problem/2178

from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().strip())) for _ in range(N)]
visited = [[0]*M for _ in range(N)]
res = 0
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(i, j):
    que = deque([(i, j)])
    while que:
        x, y = que.popleft()
        for k in range(4):
            nx, ny = x+dx[k], y+dy[k]
            if 0 <= nx < N and 0 <= ny < M:
                if graph[nx][ny] == 1 and not visited[nx][ny]:
                    visited[nx][ny] = visited[x][y]+1
                    que.append((nx, ny))


for i in range(N):
    for j in range(M):
        if graph[i][j] == 1 and not visited[i][j]:
            visited[i][j] += 1
            bfs(i, j)
print(visited[N-1][M-1])
