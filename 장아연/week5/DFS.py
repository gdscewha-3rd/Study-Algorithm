# 이코테 DFS 예제 코드

# 각 노드가 연결된 정보를 리스트 자료형으로 표현 : 2차원 리스트
graph = [[], [2, 3, 8], [1, 7], [1, 4, 5],
         [3, 5], [3, 4], [7], [2, 6, 8], [1, 7]]

# 각 노드가 방문된 정보를 리스트 자료형으로 표현
visited = [False] * 9


def dfs(graph, v, visited):
    visited[v] = True  # 현재 노드 방문 처리
    print(v, end=" ")
    for i in graph[v]:  # 현재 노드와 연결된 다른 노드 재귀적 방문
        if not visited[i]:
            dfs(graph, i, visited)


# 정의된 DFS 함수 호출
dfs(graph, 1, visited)
