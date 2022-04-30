//20220422
//프로그래머스 level2 괄호 변환 문제
//https://programmers.co.kr/learn/courses/30/lessons/60058

import Foundation

func solution(_ p:String) -> String {
    var answer = ""
    if p == ""{
        return answer
    } else {
        answer = isCorrect(p)
    }
    return answer
}

func isCorrect(_ p:String) -> String {
        if p == "" { return "" }
        var u = ""
        var v = ""
        var r = 0
        var l = 0
        for (i,w) in p .enumerated(){
            if r == l && r>0 {
                v = String(p[p.index(p.startIndex,offsetBy:i)...])
                break
            } else {
                u += String(w)
                if w == "("{ l += 1 }
                else { r += 1 }
            }
        }
        //print(u,v)
        var stack = [String]()
        var correct = false
        if u.first! == "(" {
            for i in u {
                if i == "(" {
                    stack.append(String(i))
                } else {
                    stack.removeLast()
                }
            }
            if stack.count == 0 {
                correct = true
            }
        }
        //print(u,correct)

    var new = "("

    if correct == true {
        return u + isCorrect(v)
    } else {
        new += isCorrect(v)
        new += ")"
        u.removeLast()
        u.removeFirst()
        for i in u {
            if i == "(" {
                new += ")"
            } else {
                new += "("
            }
        }
        return new
    }
}


/* 다른 사람 풀이
func solution(_ p:String) -> String {
    if p.count < 1 {return ""}

    var count = 0, index = p.startIndex
    repeat{
        count += String(p[index]) == "(" ? 1 : -1
        index = p.index(after: index)
    } while count != 0

    var u = String(p[..<index]), v = String(p[index...])
    if String(u.first!) == "("{
        return u + solution(v)
    }else{
        u.removeLast()
        u.removeFirst()
        return "(\(solution(v)))\(u.map{String($0) == "(" ? ")" : "("}.joined())"
    }
}
*/