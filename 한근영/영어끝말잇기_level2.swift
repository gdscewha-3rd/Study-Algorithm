//220323
//프로그래머스 [level2] 영어 끝말잇기 문제
//https://programmers.co.kr/learn/courses/30/lessons/12981

import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var answer = [0,0]
    var arr = [String(words.first!.first!)]
    for (i,word) in words.enumerated(){
        if arr.contains(word) == true || word.hasPrefix(String(arr.last!.last!)) == false{
            print(word)
            answer[0] = i%n+1
            answer[1] = Int(ceil(Double(i+1)/Double(n)))
            return answer
        }
        arr.append(word)
    }

    return answer
}