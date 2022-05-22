#20220521
#프로그래머스 level3 N-Queen 문제
#https://programmers.co.kr/learn/courses/30/lessons/12952?language=python3

#코드 참조
#https://junior-datalist.tistory.com/89


def solution(n):
    arr = [0]*n
    return dfs(0,arr)

def dfs(depth,arr):
    answer = 0
    if depth == len(arr) :
        return 1
    for i in range(len(arr)):
        #print("check",depth,i,check(depth,i))
        arr[depth]=i
        if check(depth,i,arr)==True:
            #print(arr)
            answer += dfs(depth+1,arr)
    return answer
        
def check(depth,i,arr): #퀸을 놓아도 되는지 여부 반환
    for j in range(depth):
        if arr[j] == i or abs(i-arr[j]) == abs(depth-j):
            return False
    return True



'''
arr = [] #열 기준

def solution(n):
    answer = 0
    if dfs(0,n,0) == True:
        answer+=1
    
    return answer

def dfs(depth,n,s): #s:간격
    if depth == n :
        return True
    for i in range(s,n):
        if check(depth,i)==True:
            arr.append(i)
            dfs(depth+1,n,0)
    if len(arr) == depth:
        last = arr[len(arr)-1]
        arr.pop()
        dfs(depth-1,n,last+1)
    
        
def check(depth,i): #퀸을 놓아도 되는지 여부 반환
    if i in arr: #같은 행에 없도록
        return False
    for i in len(arr):
        if abs(len(arr)-i) != abs(y-arr[i]):
            return False
    return True
'''