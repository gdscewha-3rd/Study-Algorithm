#220410
#프로그래머스 스킬트리
#https://programmers.co.kr/learn/courses/30/lessons/49993

def solution(skill, skill_trees):
    answer = 0
    skilllist = []
    presubject = []
    for i in range(len(skill)):
        skilllist.append(skill[i])
        presubject.append((skill[i], skill[:i]))

    skillnum = len(skilllist)

    for word in skill_trees:
        order = []
        for i in skilllist:
            if i in word:
                order.append(word.index(i))

        checknum = 0
        check = sorted(order)

        if order == check:
            mark = 0
            for i in range(len(order)):
                num = order[i]
                letter = word[num]
                if i == 0:
                    for j in presubject:
                        if j[0] == letter:
                            if j[1] == "":
                                mark += 1
                                break
                else:
                    print(i)
                    smallcheck = 0
                    preletter = ""
                    for k in range(0, i, 1):
                        prenum = order[k]
                        preletter += word[prenum]

                    for j in presubject:
                        if j[0] == letter:
                            if j[1] in preletter:
                                mark += 1
            if mark == len(order):
                answer += 1
    return answer