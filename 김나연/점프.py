#1890
#백준 1890번 점프
#https://www.acmicpc.net/problem/1890

def solution(board, n):
    dp = [[0] * n for _ in range(n)] # (i, j) 좌표까지 올 수 있는 방법 수 
    dp[0][0] = 1 #시작점부터 1 초기화

    for i in range(n):
        for j in range(n):
            if i == n-1 and j == n-1: #종료조건
                break

            go = board[i][j]
            if i+go < n:
                dp[i+go][j] += dp[i][j] 
            if j+go < n: 
                dp[i][j+go] += dp[i][j]
    
    print(dp[n-1][n-1])
n = int(input())
board = []
for i in range(n):
    board.append(list(map(int, input().split())))

solution(board, n)