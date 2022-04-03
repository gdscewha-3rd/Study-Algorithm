//220321
//프로그래머스 [level1] 실패율 문제
//https://programmers.co.kr/learn/courses/30/lessons/42889

import Foundation
//N : 5
//stages : [1,2,2,1,3]
//result : [3,2,1,4,5] <-- 이 경우 참조(player가 이미 앞에서 0이 되어버리면 nan값이 들어가버린다)
func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    var p = [Double](repeating:Double(0),count:N+1)
    var answer = [Int]()
    for i in stages {
        p[i-1]+=Double(1)
    }
    var player = stages.count

    p.removeLast()
    for i in 0...N-1 {
        if player > 0{
            var a = p[i]/Double(player)
            player -= Int(p[i]) 
            p[i] = a
        }

    }

    while(answer.count<N){
        let maxIndex = p.firstIndex(of:p.max()!)!
        answer += [Int(maxIndex)+1]
        p[maxIndex] = -1
    }

    return answer
}

//근데 반복문이 3개나,, map을 이용해 더 짧게 줄일 수 있을듯