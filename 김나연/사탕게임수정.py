#220501
#백준 3085번 사탕게임 
#https://www.acmicpc.net/problem/3085

def count(board):
    row, col, row_max, col_max = 1, 1, -1e9, -1e9
    n = len(board)
    for i in range(n): #같은 행 다른 열
        for j in range(n-1): 
            if board[i][j] == board[i][j+1]:
                row += 1
            else:
                row = 1
            row_max = max(row, row_max) #해당 행에서 연속적인 색깔 영역중 큰거 
        row = 1 #다음행을 위해 초기화

    for j in range(n): # 다른 행 같은 열 , j 주목
        for i in range(n-1):    
            if board[i][j] == board[i+1][j]: 
                col += 1
            else:
                col = 1
            col_max = max(col_max, col)
        col = 1
    answer = max(row_max, col_max)
    return answer

n = int(input())
board = []
#for i in range(n): # list(문자열) -> [한글자씩]
#   board.append(list(input()))
board = [list(input()) for _ in range(n)]
result = 0

de = [[-1, 0], [1, 0], [0,-1], [0, 1]] #상하좌우

for i in range(n):
    for j in range(n): #모든 좌표 

        for k in range(4): #4가지 방향
            nx = i + de[k][0]
            ny = j + de[k][1]

            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if board[i][j] != board[nx][ny]:
                board[i][j], board[nx][ny] = board[nx][ny], board[i][j]
                result = max(result, count(board))
                board[i][j], board[nx][ny] = board[nx][ny], board[i][j] #원위치
                
print(board)