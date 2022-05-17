#220515
#백준 1062 가르침 
#https://www.acmicpc.net/problem/1062

#k개 글자 가르침, 모든 단어는 "anta"로 시작되고, "tica"로 끝
#남극언어에 단어는 N개 
#anta tica => a,n,t,i,c 5개 글자는 반드시 배워야하고 26개 배우면 모든 단어 읽을 수 있음 
import sys
n, k = map(int, input().split())

if k < 5:
    print(0)
    exit()
elif k == 26:
    print(n)
    exit()

words = [set(sys.stdin.readline().rstrip()) for _ in range(n)] #sys.stdin.readline은 개행문자까지 읽어듬 
learn = [0] * 26  #배운 글자 저장

for c in ['a','n','t', 'i', 'c']:
    learn[ord(c) - ord('a')] = 1   #ord('a')가 learn[0]

def dfs(idx, cnt): #         cnt: 'a','n','t', 'i', 'c' 빼고 배운 글자 수  
    global answer

    if cnt == k - 5: # cnt + 5 = k, k개만큼 글자 배우면 얼마나 단어를 읽을 수 있는지 확인  
        readcnt = 0  #읽을 수 있는 단어수 
        for word in words:  #word: ('', '' ....)
            check = True 
            for w in word:  
                if not learn[ord(w) - ord('a')]:    #안 배운 글자가 있으면 루프 나옴 
                    check = False 
                    break
            if check: #해당 word는 읽을 수 있음 
                readcnt += 1 
        answer = max(answer, readcnt)
        return

    for i in range(idx, 26): #26개 글자 
        if not learn[i]: #i번 배우지 않았으면 배운걸로 하고 
            learn[i] = True 
            dfs(i, cnt + 1) 
            learn[i] = False #다시 안 배운걸로 


dfs(0, 0)
print(answer) 
