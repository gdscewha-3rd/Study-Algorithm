#1700
#백준 1700번 멀티탭스케줄링 
#https://www.acmicpc.net/problem/1700

n, k = map(int, input().split())
multi = list(map(int, input().split())) #k 크기만큼 전기용품 순서 
plug = []
answer = 0

for i in range(k): #전기 용품 총 사용수만큼 반복

    if multi[i] in plug: #이미 플러그에 꽂음  
        continue
    if len(plug) < n: #플러그에 꽂은 전기용품이 n개 아니면 그냥 꽂음 
        plug.append(multi[i])
        continue

    #플러그에 자리 없음 
    countnextmulti = []

    for j in range(n): # 플러그에 꽂혀있는거 멀티에 현재위치(i)이후 확인
        if plug[j] in multi[i:]: 
            idx = multi[i:].index(plug[j]) #멀티에서 인덱스 
        else:
            idx = 101  
            flag = False

        countnextmulti.append(idx)
    
    #len(countnextmulti) = n 
    maxidx = countnextmulti.index(max(countnextmulti)) #countnextmulti 가장 큰 값의 인덱스 
    del plug[maxidx]
    plug.append(multi[i])
    answer += 1

print(answer)