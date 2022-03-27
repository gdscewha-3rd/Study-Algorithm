#220327
#백준 15486번 퇴사2 
#https://www.acmicpc.net/problem/15486

from sys import stdin
def solution(n, daylist, pricelist):
    maxprice = 0
    dp = [0] * (n+1)
    endday = 0

    k = 0
    for i in range(n):
        k = max(k, dp[i])
        if i+daylist[i] > n:
            continue
        dp[i+daylist[i]] = max(k+pricelist[i], dp[i+daylist[i]])
    maxprice = max(dp) 
    return maxprice

n = int(input())
daylist = []
pricelist = []
for i in range(n):
    day, price = map(int, stdin.readline().split())
    daylist.append(day)
    pricelist.append(price)
answer = solution(n, daylist, pricelist)
print(answer)