#220514
#백준 14719 빗물 
#https://www.acmicpc.net/problem/14719

h, w = map(int, input().split()) #블록 쌓인거 최대 높이 h 블록수 w 
blocks = list(map(int, input().split()))
answer = 0

if not blocks:  # 예외 처리
    print(0)
    exit()

left, right = 0, len(blocks) - 1  #양끝 인덱스 
leftmax, rightmax = blocks[left], blocks[right]

while left < right: 
    leftmax, rightmax = max(blocks[left], leftmax), max(blocks[right], rightmax)
    if leftmax <= rightmax:  # 투 포인터가 최대값으로 향하도록 이동 
        answer += leftmax - blocks[left]
        left += 1
    else:
        answer += rightmax - blocks[right]
        right -= 1
print(answer)